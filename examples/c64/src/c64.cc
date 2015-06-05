#include "c64.hh"
#include "cpu/mos_6510.hh"

#include "harpoon/clock/clock.hh"
#include "harpoon/clock/generator/threaded_generator.hh"
#include "harpoon/execution/up_execution_unit.hh"
#include "harpoon/memory/main_memory.hh"
#include "harpoon/memory/linear_read_only_memory.hh"
#include "harpoon/memory/linear_random_access_memory.hh"
#include "harpoon/memory/serializer/binary_file.hh"

using namespace commodore;

c64::c64(const harpoon::log::log_ptr& log)
	: harpoon::computer_system("Commodore 64") {
	set_log(log);
}

c64::~c64() {}

void c64::create() {
	create_memory();
	create_execution_unit();
}

void c64::create_execution_unit() {
	auto execution_unit = harpoon::execution::make_up_execution_unit("Execution unit");
	set_main_execution_unit(execution_unit);

	auto clock = harpoon::clock::make_clock(
		std::static_pointer_cast<harpoon::clock::generator::generator>(
			harpoon::clock::generator::make_threaded_generator(1000000)), "Clock");
	execution_unit->set_clock(clock);

	auto cpu = std::make_shared<cpu::mos_6510>("CPU");
	execution_unit->set_processing_unit(cpu);

	cpu->create();
}

void c64::create_memory() {
	auto main_memory = harpoon::memory::make_main_memory("Memory", harpoon::memory::address_range{0, 0xffff});
	set_main_memory(main_memory);

	auto kernal = make_linear_read_only_memory("Kernal", harpoon::memory::address_range{0xe000, 0xffff});
	main_memory->add_memory(kernal);
	_kernal = kernal;

	auto ram = make_linear_random_access_memory("RAM", harpoon::memory::address_range{0, 0xdfff});
	main_memory->add_memory(ram);
}

void c64::prepare() {
	auto execution_unit = std::static_pointer_cast<harpoon::execution::up_execution_unit>(get_main_execution_unit());
	auto cpu = std::static_pointer_cast<cpu::mos_6510>(execution_unit->get_processing_unit());
	cpu->set_memory(get_main_memory());
	harpoon::computer_system::prepare();

	load_kernal();
}

void c64::load_kernal() {
	harpoon::memory::serializer::binary_file kernal_bin("kernal.rom");
	_kernal.lock()->deserialize(kernal_bin);
}
