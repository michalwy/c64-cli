#include "mos_6502.hh"
#include "mos_6502_decoder.hh"

using namespace commodore::cpu;

namespace {
	static constexpr const std::uint16_t RESET_VECTOR = 0xfffc;
}

mos_6502::~mos_6502() {}

void mos_6502::create() {
	auto decoder = std::make_shared<mos_6502_decoder>(this, "Decoder");
	add_component(decoder);
	_decoder = decoder;
}

void mos_6502::init_registers() {
	_registers.A = 0xaa;
	_registers.X = 0;
	_registers.Y = 0;
	_registers.PC = 0;
	_registers.SP = 0;
	_registers.IR = 0;
}

void mos_6502::boot() {
	init_registers();
	harpoon::execution::processing_unit::boot();
}

std::uint_fast64_t mos_6502::begin_execution() {

	auto memory = get_memory();

	_registers.SP = 0;
	_registers.IR = 0;

	_registers.SP--;
	_registers.SP--;
	_registers.SP--;

	memory->get(RESET_VECTOR, _registers.PC);

	return 9;
}

std::uint_fast64_t mos_6502::fetch_decode(harpoon::execution::instruction_handler& instruction_handler) {
	return _decoder.lock()->decode(instruction_handler);
}

void mos_6502::log_registers(harpoon::log::message::Level level) const {
	log(component_log(level) << "A:  " << _registers.A << "    X: " << _registers.X << "  Y: " << _registers.Y);
	log(component_log(level) << "PC: " << _registers.PC << " SP: " << _registers.SP << " IR: " << _registers.IR);
}
