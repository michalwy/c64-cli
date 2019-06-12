#ifndef CPU_INSTRUCTIONS_PLA_HH
#define CPU_INSTRUCTIONS_PLA_HH

#include "harpoon/execution/instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {
namespace pla {

struct implied {
	static constexpr const std::uint8_t OPCODE = 0x68;
	static harpoon::execution::instruction factory(harpoon::execution::processing_unit *cpu);
};

} // namespace pla
} // namespace instructions
} // namespace cpu
} // namespace commodore

#endif
