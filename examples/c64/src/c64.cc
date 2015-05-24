#include "c64.hh"
#include "cpu/mos_6502.hh"

#include "harpoon/execution/up_execution_unit.hh"
#include "harpoon/clock/clock.hh"
#include "harpoon/clock/generator/threaded_generator.hh"

using namespace commodore;

c64::c64(const harpoon::log::log_ptr& log)
	: harpoon::computer_system("Commodore 64") {
	set_log(log);
}

c64::~c64() {}

void c64::create() {
	create_execution_unit();
}

void c64::create_execution_unit() {
	auto execution_unit = harpoon::execution::make_up_execution_unit("Execution unit");
	set_main_execution_unit(execution_unit);

	auto clock = harpoon::clock::make_clock(
		std::static_pointer_cast<harpoon::clock::generator::generator>(
			harpoon::clock::generator::make_threaded_generator(1000000)), "Clock");
	execution_unit->set_clock(clock);

	auto cpu = std::make_shared<cpu::mos_6502>("CPU");
	execution_unit->set_processing_unit(cpu);
}
