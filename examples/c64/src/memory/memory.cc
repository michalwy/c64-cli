#include "memory.hh"

#include "harpoon/memory/linear_read_only_memory.hh"
#include "harpoon/memory/chunked_random_access_memory.hh"
#include "harpoon/memory/serializer/binary_file.hh"

using namespace commodore::memory;

memory::~memory() {}

void memory::create() {

	auto read_memory = harpoon::memory::make_main_memory("Read memory", harpoon::memory::address_range{0x0000, 0xffff});
	auto write_memory = harpoon::memory::make_main_memory("Write memory", harpoon::memory::address_range{0x0000, 0xffff});

	_read_memory = read_memory;
	_write_memory = write_memory;

	add_component(read_memory);
	add_component(write_memory);

	auto kernal = make_linear_read_only_memory("ROM Kernal", harpoon::memory::address_range{0xe000, 0xffff});
	add_component(kernal);
	_kernal_e000_ffff = kernal;
	read_memory->add_memory(_kernal_e000_ffff, false);

	auto basic = make_linear_read_only_memory("ROM BASIC", harpoon::memory::address_range{0xa000, 0xbfff});
	add_component(basic);
	_basic_a000_bfff = basic;
	read_memory->add_memory(_basic_a000_bfff, false);

	auto ram = make_chunked_random_access_memory("RAM $0000", harpoon::memory::address_range{0, 0x3fff}, 1024);
	add_component(ram);
	read_memory->add_memory(ram, false);
	write_memory->add_memory(ram, false);

	ram = make_chunked_random_access_memory("RAM $4000", harpoon::memory::address_range{0x4000, 0x7fff}, 1024);
	add_component(ram);
	read_memory->add_memory(ram, false);
	write_memory->add_memory(ram, false);

	ram = make_chunked_random_access_memory("RAM $8000", harpoon::memory::address_range{0x8000, 0x9fff}, 1024);
	add_component(ram);
	read_memory->add_memory(ram, false);
	write_memory->add_memory(ram, false);

	ram = make_chunked_random_access_memory("RAM $A000", harpoon::memory::address_range{0xa000, 0xbfff}, 1024);
	add_component(ram);
	read_memory->add_memory(ram, false);
	write_memory->add_memory(ram, false);

	ram = make_chunked_random_access_memory("RAM $C000", harpoon::memory::address_range{0xc000, 0xcfff}, 1024);
	add_component(ram);
	read_memory->add_memory(ram, false);
	write_memory->add_memory(ram, false);

	ram = make_chunked_random_access_memory("RAM $D000", harpoon::memory::address_range{0xd000, 0xdfff}, 1024);
	add_component(ram);
	read_memory->add_memory(ram, false);
	write_memory->add_memory(ram, false);

	ram = make_chunked_random_access_memory("RAM $E000", harpoon::memory::address_range{0xe000, 0xffff}, 1024);
	add_component(ram);
	write_memory->add_memory(ram, false);

}

void memory::prepare() {
	harpoon::memory::main_memory::prepare();

	load_kernal();
}

void memory::load_kernal() {
	harpoon::memory::serializer::binary_file kernal_bin("kernal.rom");
	_kernal_e000_ffff.lock()->deserialize(kernal_bin);
}

void memory::get(harpoon::memory::address address, std::uint8_t& value) {
	_read_memory.lock()->get(address, value);
}

void memory::set(harpoon::memory::address address, std::uint8_t value) {
	_write_memory.lock()->set(address, value);
}
