#ifndef CPU_INSTRUCTIONS_MOS_6510_INSTRUCTION_HH
#define CPU_INSTRUCTIONS_MOS_6510_INSTRUCTION_HH

#include "../mos_6510.hh"

#include "harpoon/execution/instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

template<std::uint8_t OP, std::size_t LEN, std::uint_fast64_t CYCLES>
class mos_6510_instruction : public harpoon::execution::instruction<mos_6510> {
public:
	static constexpr const std::uint8_t OPCODE = OP;
	static constexpr const std::uint_fast64_t CYCLES_EXECUTE = CYCLES;
	static constexpr const std::size_t LENGTH = LEN;
};

template<std::uint8_t OP, std::uint_fast64_t CYCLES>
class mos_6510_nullary_instruction : public mos_6510_instruction<OP, 1, CYCLES> {
};

template<std::uint8_t OP, typename OPERAND, std::uint_fast64_t CYCLES>
class mos_6510_unary_instruction : public mos_6510_instruction<OP, 1+sizeof(OPERAND), CYCLES> {
public:
	void decode() {
		this->get_cpu()->get_decoder()->get_program_code(_operand, 1);
	}

protected:
	OPERAND _operand{};
};

}
}
}

#endif

