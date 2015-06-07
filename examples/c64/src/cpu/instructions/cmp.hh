#ifndef CPU_INSTRUCTIONS_CMP_HH
#define CPU_INSTRUCTIONS_CMP_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

template<std::uint8_t OP, typename OPERAND, std::uint_fast64_t CYCLES>
class cmp : public mos_6510_mem_unary_instruction<OP, OPERAND, CYCLES> {};

class cmp_absolute_x : public cmp<0xDD, std::uint16_t, 4> {
public:
	void execute() {
		std::uint8_t mem{}, a{}, res{};
		get_absolute_x(mem);
		a = get_cpu()->get_registers().A;
		res = a - mem;
		update_flags_ZN(get_cpu(), res);
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble_absolute_x(stream, "CMP");
	}
};

class cmp_indirect_y : public cmp<0xD1, std::uint8_t, 5> {
public:
	void execute() {
		std::uint8_t mem{}, a{}, res{};
		get_indirect_y(mem);
		a = get_cpu()->get_registers().A;
		res = a - mem;
		update_flags_ZN(get_cpu(), res);
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble_indirect_y(stream, "CMP");
	}
};

}
}
}

#endif

