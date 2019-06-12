#ifndef CPU_INSTRUCTIONS_PLP_HH
#define CPU_INSTRUCTIONS_PLP_HH

#include "harpoon/execution/instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {
namespace plp {

struct implied {
	static constexpr const std::uint8_t OPCODE = 0x28;
	static harpoon::execution::instruction factory(harpoon::execution::processing_unit *cpu);
};

} // namespace plp
} // namespace instructions
} // namespace cpu
} // namespace commodore

#endif
