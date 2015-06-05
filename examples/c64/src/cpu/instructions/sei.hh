#ifndef CPU_INSTRUCTIONS_SEI_HH
#define CPU_INSTRUCTIONS_SEI_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

class sei : public mos_6510_nullary_instruction<0x9A, 2> {
public:
	void execute() {
		get_cpu()->get_registers().P.I() = true;
	}
};

}
}
}

#endif

