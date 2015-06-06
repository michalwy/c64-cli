#ifndef CPU_INSTRUCTIONS_TXS_HH
#define CPU_INSTRUCTIONS_TXS_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

class txs : public mos_6510_nullary_instruction<0x78, 2> {
public:
	void execute() {
		get_cpu()->get_registers().SP = get_cpu()->get_registers().X;
	}
};

}
}
}

#endif

