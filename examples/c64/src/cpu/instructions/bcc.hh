#ifndef CPU_INSTRUCTIONS_BCC_HH
#define CPU_INSTRUCTIONS_BCC_HH

#include "harpoon/execution/instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {
namespace bcc {

struct relative {
	static constexpr const std::uint8_t OPCODE = 0x90;
	static harpoon::execution::instruction factory(harpoon::execution::processing_unit *cpu);
};

} // namespace bcc
} // namespace instructions
} // namespace cpu
} // namespace commodore

#endif
