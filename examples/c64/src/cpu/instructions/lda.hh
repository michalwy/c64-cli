#ifndef CPU_INSTRUCTIONS_LDA_HH
#define CPU_INSTRUCTIONS_LDA_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

template<std::uint8_t OP, typename OPERAND, std::uint_fast64_t CYCLES>
class lda : public mos_6510_a_unary_instruction<OP, OPERAND, CYCLES>{};

class lda_immediate : public lda<0xA9, std::uint8_t, 2> {
public:
	void execute() {
		this->get_cpu()->get_registers().A = _operand;
		update_flags_ZN(get_cpu());
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble_immediate(stream, "LDA");
	}

};

class lda_absolute : public lda<0xAD, std::uint16_t, 4> {
public:
	void execute() {
		get_absolute(get_cpu()->get_registers().A);
		update_flags_ZN(get_cpu());
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble_absolute(stream, "LDA");
	}
};

class lda_absolute_x : public lda<0xBD, std::uint16_t, 4> {
public:
	void execute() {
		get_absolute_x(get_cpu()->get_registers().A);
		update_flags_ZN(get_cpu());
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble_absolute_x(stream, "LDA");
	}
};

class lda_indirect_y : public lda<0xB1, std::uint8_t, 5> {
public:
	void execute() {
		get_indirect_y(get_cpu()->get_registers().A);
		update_flags_ZN(get_cpu());
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble_indirect_y(stream, "LDA");
	}
};

}
}
}

#endif

