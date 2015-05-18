#include "harpoon/memory/chunked_memory.hh"
#include "harpoon/memory/exception/memory_exception.hh"
#include "harpoon/memory/exception/read_access_violation.hh"
#include "harpoon/memory/exception/write_access_violation.hh"

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
		log(component_debug << "Allocating chunk #" << get_chunk_index(address));
		chunk.reset(new uint8_t[_chunk_length], std::default_delete<chunk_item[]>());
	}

	chunk_offset offset = get_chunk_offset(address);
	chunk.get()[offset] = value;
}
