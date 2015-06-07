#ifndef CPU_INSTRUCTIONS_INC_HH
#define CPU_INSTRUCTIONS_INC_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

template<std::uint8_t OP, typename OPERAND, std::uint_fast64_t CYCLES>
class inc : public mos_6510_mem_unary_instruction<OP, OPERAND, CYCLES> {};

class inc_zero_page : public inc<0xE6, std::uint8_t, 5> {
public:
	void execute() {
		std::uint8_t m{};
		get_zero_page(m);
		m++;
		set_zero_page(m);
		update_flags_ZN(get_cpu(), m);
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble_absolute(stream, "INC");
	}
};

}
}
}

#endif

