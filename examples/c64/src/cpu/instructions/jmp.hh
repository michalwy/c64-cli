#ifndef CPU_INSTRUCTIONS_JMP_HH
#define CPU_INSTRUCTIONS_JMP_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

class jmp_absolute : public mos_6510_unary_instruction<0x4c, std::uint16_t, 3> {
public:
	void execute() {
		get_cpu()->get_registers().PC = _operand;
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble_absolute(stream, "JMP");
	}
};

}
}
}

#endif

