#ifndef CPU_INSTRUCTIONS_ADC_HH
#define CPU_INSTRUCTIONS_ADC_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

template<std::uint8_t OP, typename OPERAND, std::uint_fast64_t CYCLES>
class adc : public mos_6510_a_unary_instruction<OP, OPERAND, CYCLES> {};

class adc_immediate : public adc<0x69, std::uint8_t, 2> {
public:
	void execute() {
		std::uint16_t a = get_cpu()->get_registers().A;
		a += _operand;
		get_cpu()->get_registers().A = (a & 0xff);
		update_flags_ZNCV(get_cpu(), (a & 0x100) == 0x100, false);
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble_immediate(stream, "ADC");
	}

};

}
}
}

#endif

