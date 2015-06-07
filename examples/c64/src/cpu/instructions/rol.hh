#ifndef CPU_INSTRUCTIONS_ROL_HH
#define CPU_INSTRUCTIONS_ROL_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

template<std::uint8_t OP, typename OPERAND, std::uint_fast64_t CYCLES>
class rol : public mos_6510_mem_unary_instruction<OP, OPERAND, CYCLES> {};

class rol_accumulator : public mos_6510_a_nullary_instruction<0x2A, 2> {
public:
	void execute() {
		std::uint8_t a = get_cpu()->get_registers().A;
		get_cpu()->get_registers().A <<= 1;
		get_cpu()->get_registers().A |= (get_cpu()->get_registers().P.C() ? 1 : 0);
		update_flags_ZN(get_cpu());
		get_cpu()->get_registers().P.C() = ((a & 0x80) == 0x80);
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble(stream, "ROL");
	}

};

}
}
}

#endif

