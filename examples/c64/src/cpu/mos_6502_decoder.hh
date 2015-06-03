#ifndef CPU_MOS_6502_DECODER_HH
#define CPU_MOS_6502_DECODER_HH

#include "harpoon/execution/instruction.hh"

namespace commodore {
namespace cpu {

class mos_6502;

class mos_6502_decoder {
public:

	mos_6502_decoder(mos_6502 * cpu) : _cpu(cpu) {}

	std::uint_fast64_t decode(harpoon::execution::instruction_handler& instruction_handler);

private:

	std::uint8_t get_instruction_byte(std::uint_fast64_t offset);

	mos_6502 * _cpu;
};

}
}

#endif

