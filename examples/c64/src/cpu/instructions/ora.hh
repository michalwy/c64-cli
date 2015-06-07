#ifndef CPU_INSTRUCTIONS_ORA_HH
#define CPU_INSTRUCTIONS_ORA_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

template<std::uint8_t OP, typename OPERAND, std::uint_fast64_t CYCLES>
class ora : public mos_6510_a_unary_instruction<OP, OPERAND, CYCLES> {};

class ora_immediate : public ora<0x09, std::uint8_t, 2> {
public:
	void execute() {
		get_cpu()->get_registers().A |= _operand;
		update_flags_ZN(get_cpu());
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble_immediate(stream, "ORA");
	}

};

}
}
}

#endif

