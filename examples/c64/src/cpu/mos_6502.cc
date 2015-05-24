#include "mos_6502.hh"

using namespace commodore::cpu;

mos_6502::~mos_6502() {}

void mos_6502::init_registers() {
	_registers.A.set_value(0);
	_registers.X.set_value(0);
	_registers.Y.set_value(0);
	_registers.PC.set_value(0);
	_registers.S.set_value(0);
}

void mos_6502::boot() {
	init_registers();
	harpoon::execution::processing_unit::boot();
}

std::uint_fast64_t mos_6502::fetch() {
	return 1;
}

std::uint_fast64_t mos_6502::execute() {
	return 4;
}

void mos_6502::log_registers(harpoon::log::message::Level level) const {
	log(component_log(level) << "A:  " << _registers.A << "   X: " << _registers.X << " Y: " << _registers.Y);
	log(component_log(level) << "PC: " << _registers.PC << " S: " << _registers.S);
}
