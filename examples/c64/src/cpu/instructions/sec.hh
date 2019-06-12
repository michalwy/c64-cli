#ifndef CPU_INSTRUCTIONS_SEC_HH
#define CPU_INSTRUCTIONS_SEC_HH

#include "harpoon/execution/instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {
namespace sec {

struct implied {
	static constexpr const std::uint8_t OPCODE = 0x38;
	static harpoon::execution::instruction factory(harpoon::execution::processing_unit *cpu);
};

} // namespace sec
} // namespace instructions
} // namespace cpu
} // namespace commodore

#endif
