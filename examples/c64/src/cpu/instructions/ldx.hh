#ifndef CPU_INSTRUCTIONS_LDX_HH
#define CPU_INSTRUCTIONS_LDX_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

template<std::uint8_t OP, typename OPERAND, std::uint_fast64_t CYCLES>
class ldx : public mos_6510_x_unary_instruction<OP, OPERAND, CYCLES> {};

class ldx_immediate : public ldx<0xA2, std::uint8_t, 2> {
public:
	void execute() {
		get_cpu()->get_registers().X = _operand;
		update_flags_ZN(get_cpu());
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble_immediate(stream, "LDX");
	}

};

}
}
}

#endif
