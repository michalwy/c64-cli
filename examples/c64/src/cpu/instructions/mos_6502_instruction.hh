#ifndef CPU_INSTRUCTIONS_MOS_6502_INSTRUCTION_HH
#define CPU_INSTRUCTIONS_MOS_6502_INSTRUCTION_HH

#include "harpoon/execution/instruction.hh"

namespace commodore {
namespace cpu {
class mos_6502;
}
}

namespace commodore {
namespace cpu {
namespace instructions {

class mos_6502_instruction : public harpoon::execution::instruction<mos_6502> {
public:
};

}
}
}

#endif

