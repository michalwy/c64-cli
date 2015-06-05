#include "harpoon/memory/chunked_memory.hh"
#include "harpoon/memory/exception/memory_exception.hh"
#include "harpoon/memory/exception/read_access_violation.hh"
#include "harpoon/memory/exception/write_access_violation.hh"
#include "harpoon/memory/serializer/serializer.hh"

using namespace harpoon::memory;

chunked_memory::~chunked_memory() {}

void chunked_memory::prepare() {
	auto len = get_address_range().get_length();

	if (0 == len) {
		throw COMPONENT_EXCEPTION(exception::memory_exception, "Zero-length memory block.");
	}
	if (0 == _chunk_length) {
		throw COMPONENT_EXCEPTION(exception::memory_exception, "Invalid chunk length (0).");
	}

	chunk_container::size_type chunks = static_cast<chunk_container::size_type>(len / _chunk_length);
	if (0 < len % _chunk_length) {
		chunks++;
	}

	log(component_notice << "Chunking " << len << " bytes of memory into " << chunks << " chunks of " << _chunk_length << " bytes each");
	_memory.resize(chunks);

	memory::prepare();
}

void chunked_memory::cleanup() {
	memory::cleanup();
	log(component_notice << "Freeing memory");
	_memory.clear();
}

void chunked_memory::get(address address, uint8_t& value) {
	if (!has_address(address)) {
		throw COMPONENT_EXCEPTION(exception::read_access_violation, address);
	}

	const chunk_ptr& chunk = get_chunk(address);
	if (chunk) {
		chunk_offset offset = get_chunk_offset(address);
		value = chunk.get()[offset];
	}
}

void chunked_memory::set(address address, uint8_t value) {
	if (!has_address(address)) {
		throw COMPONENT_EXCEPTION(exception::write_access_violation, address);
	}

	chunk_ptr& chunk = get_chunk(address);
	if (!chunk) {
		allocate_chunk(chunk, address);
	}

	chunk_offset offset = get_chunk_offset(address);
	chunk.get()[offset] = value;
}

inline void chunked_memory::allocate_chunk(chunk_ptr& chunk, address address) {
	log(component_debug << "Allocating chunk #" << get_chunk_index(address));
	chunk.reset(new uint8_t[_chunk_length], std::default_delete<chunk_item[]>());
}

void chunked_memory::serialize(serializer::serializer& serializer) {
	serializer.start_memory_block(this, get_address_range());
	for (address address = get_address_range().get_start(); address < get_address_range().get_end(); address += _chunk_length) {
		chunk_ptr& chunk = get_chunk(address);
		serializer.write(chunk.get(), _chunk_length, !chunk);
	}
	serializer.end_memory_block();
}

void chunked_memory::deserialize(serializer::serializer& serializer) {
	serializer.seek_memory_block(this, get_address_range());

	for (address address = get_address_range().get_start(); address < get_address_range().get_end(); address += _chunk_length) {
		chunk_ptr& chunk = get_chunk(address);
		if (!chunk) {
			allocate_chunk(chunk, address);
		}
		if (serializer.read(chunk.get(), _chunk_length) < _chunk_length) {
			return;
		}
	}
}
