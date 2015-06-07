#ifndef CPU_INSTRUCTIONS_AND_HH
#define CPU_INSTRUCTIONS_AND_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

template<std::uint8_t OP, typename OPERAND, std::uint_fast64_t CYCLES>
class and : public mos_6510_a_unary_instruction<OP, OPERAND, CYCLES> {};

class and_immediate : public and<0x29, std::uint8_t, 2> {
public:
	void execute() {
		get_cpu()->get_registers().A &= _operand;
		update_flags_ZN(get_cpu());
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble_immediate(stream, "AND");
	}

};

}
}
}

#endif

