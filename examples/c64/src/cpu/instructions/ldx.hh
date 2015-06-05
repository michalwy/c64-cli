#ifndef CPU_INSTRUCTIONS_LDX_HH
#define CPU_INSTRUCTIONS_LDX_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

class ldx_immediate : public mos_6510_unary_instruction<0xA2, std::uint8_t, 2> {
public:
	void execute() {
		this->get_cpu()->get_registers().X = _operand;
	}
};

}
}
}

#endif

