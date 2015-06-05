#include "mos_6502_decoder.hh"
#include "mos_6502.hh"
#include "instructions/mos_6502.hh"

using namespace commodore::cpu;

namespace {

template<typename T>
class mos_6502_instruction_decoder : public harpoon::execution::instruction_decoder<T, mos_6502> {};

}

template<typename T>
void mos_6502_decoder::register_instruction() {
	_instruction_map[T::OPCODE] = mos_6502_instruction_decoder<T>();
}

mos_6502_decoder::mos_6502_decoder(mos_6502 * cpu) : _cpu(cpu) {
	register_instruction<instructions::nop>();
}

std::uint_fast64_t mos_6502_decoder::decode(harpoon::execution::instruction_handler& instruction_handler) {
	std::uint8_t opcode = get_instruction_byte(0);
	std::size_t pc_increment = 0;
	const auto& decoder = _instruction_map[opcode];

	if (!decoder) {
		throw std::runtime_error("unknown opcode");
	}

	auto cycles = decoder(_cpu, instruction_handler, pc_increment);

	_cpu->get_registers().PC += static_cast<std::uint16_t>(pc_increment);

	return cycles;
}

std::uint8_t mos_6502_decoder::get_instruction_byte(std::uint_fast64_t offset) {
	std::uint8_t opbyte{};
	const auto& memory = _cpu->get_memory();

	memory->get(_cpu->get_PC() + offset, opbyte);
	return opbyte;
}
