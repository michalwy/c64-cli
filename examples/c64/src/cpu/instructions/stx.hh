#ifndef CPU_INSTRUCTIONS_STX_HH
#define CPU_INSTRUCTIONS_STX_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

class stx_absolute : public mos_6510_unary_instruction<0x8E, std::uint16_t, 4> {
public:
	void execute() {
		get_cpu()->get_memory()->set(_operand, get_cpu()->get_registers().X);
	}
};

}
}
}

#endif

