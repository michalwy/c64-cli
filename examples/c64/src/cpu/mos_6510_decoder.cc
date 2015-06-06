#include "mos_6510_decoder.hh"
#include "mos_6510.hh"
#include "instructions/mos_6510.hh"

#include "harpoon/execution/exception/invalid_instruction.hh"

using namespace commodore::cpu;

namespace {

template<typename T>
class mos_6510_instruction_decoder : public harpoon::execution::instruction_decoder<T, mos_6510> {};

}

mos_6510_decoder::mos_6510_decoder(mos_6510 * cpu, const std::string& name)
	: harpoon::hardware_component(name), _cpu(cpu) {}

mos_6510_decoder::~mos_6510_decoder() {}

template<typename T>
void mos_6510_decoder::register_instruction() {
	_instruction_map[T::OPCODE] = mos_6510_instruction_decoder<T>();
	log(component_debug << "Registered instruction with opcode 0x"
		<< std::hex << std::setfill('0') << std::setw(2) << static_cast<std::uint32_t>(T::OPCODE));
}

void mos_6510_decoder::prepare() {
	register_instruction<instructions::bne>();
	register_instruction<instructions::cld>();
	register_instruction<instructions::cmp_absolute_x>();
	register_instruction<instructions::jsr>();
	register_instruction<instructions::lda_absolute_x>();
	register_instruction<instructions::ldx_immediate>();
	register_instruction<instructions::nop>();
	register_instruction<instructions::rts>();
	register_instruction<instructions::sei>();
	register_instruction<instructions::stx_absolute>();
	register_instruction<instructions::txs>();
}

std::uint_fast64_t mos_6510_decoder::decode(harpoon::execution::instruction_handler& instruction_handler) {
	std::uint8_t opcode = get_instruction_byte(0);
	std::size_t pc_increment = 0;

	_cpu->get_registers().IR = opcode;

	const auto& decoder = _instruction_map[opcode];
	if (!decoder) {
		throw COMPONENT_EXCEPTION0(harpoon::execution::exception::invalid_instruction);
	}

	auto cycles = decoder(_cpu, instruction_handler, pc_increment);

	_cpu->get_registers().PC += static_cast<std::uint16_t>(pc_increment);

	return cycles;
}

std::uint8_t mos_6510_decoder::get_instruction_byte(std::uint_fast64_t offset) {
	std::uint8_t opbyte{};
	get_program_code(opbyte, offset);
	return opbyte;
}
