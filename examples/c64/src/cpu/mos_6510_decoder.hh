#ifndef CPU_MOS_6510_DECODER_HH
#define CPU_MOS_6510_DECODER_HH

#include "harpoon/hardware_component.hh"
#include "harpoon/execution/instruction.hh"
#include "harpoon/execution/instruction_decoder.hh"

#include <array>

namespace commodore {
namespace cpu {

class mos_6510;

class mos_6510_decoder : public harpoon::hardware_component {
public:

	mos_6510_decoder(mos_6510 * cpu, const std::string& name = {});

	std::uint_fast64_t decode(harpoon::execution::instruction_handler& instruction_handler);

private:

	template<typename T>
	void register_instruction();

	std::uint8_t get_instruction_byte(std::uint_fast64_t offset);

	mos_6510 * _cpu;
	std::array<harpoon::execution::instruction_decode_handler<mos_6510>, 256> _instruction_map{};
};

}
}

#endif

