#ifndef CPU_INSTRUCTIONS_LDA_HH
#define CPU_INSTRUCTIONS_LDA_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

class lda_absolute_x : public mos_6510_unary_instruction<0xBD, std::uint16_t, 4> {
public:
	void execute() {
		get_cpu()->get_memory()->get(_operand + get_cpu()->get_registers().X, get_cpu()->get_registers().A);
		get_cpu()->get_registers().P.Z() = (get_cpu()->get_registers().A == 0);
		get_cpu()->get_registers().P.N() = ((get_cpu()->get_registers().A & 0x80) == 0x80);
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble_absolute_x(stream, "LDA");
	}
};

}
}
}

#endif

