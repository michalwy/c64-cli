#ifndef CPU_INSTRUCTIONS_CPX_HH
#define CPU_INSTRUCTIONS_CPX_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

template<std::uint8_t OP, typename OPERAND, std::uint_fast64_t CYCLES>
class cpx : public mos_6510_x_unary_instruction<OP, OPERAND, CYCLES> {};

class cpx_immediate : public cmp<0xE0, std::uint8_t, 2> {
public:
	void execute() {
		std::uint8_t res{};
		res = get_cpu()->get_registers().X - _operand;
		update_flags_ZN(get_cpu(), res);
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble_absolute_x(stream, "CPX");
	}
};

}
}
}

#endif

