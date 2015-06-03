#ifndef CPU_INSTRUCTIONS_NOP_HH
#define CPU_INSTRUCTIONS_NOP_HH

#include "mos_6502_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

class nop : public mos_6502_instruction {
public:

	static constexpr const std::uint_fast64_t CYCLES_EXECUTE = 10;
	static constexpr const std::size_t LENGTH = 2;
};

}
}
}

#endif

