#ifndef CPU_INSTRUCTIONS_BNE_HH
#define CPU_INSTRUCTIONS_BNE_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

class bne : public mos_6510_unary_instruction<0xD0, std::uint8_t, 2> {
public:
	void execute() {
		if (!get_cpu()->get_registers().P.Z()) {
			std::int8_t offset = static_cast<std::int8_t>(_operand);
			get_cpu()->get_registers().PC += offset;
		}
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble_relative(stream, "BNE");
	}
};

}
}
}

#endif

