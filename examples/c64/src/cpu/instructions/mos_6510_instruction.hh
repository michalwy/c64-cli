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

	template<typename T>
	void disassemble_hex(std::ostream& stream, T value) const {
		stream << std::uppercase << std::hex << std::setw(sizeof(T) << 1) << std::setfill('0') << static_cast<std::uint64_t>(value);
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble(stream);
	}

protected:
	void mos_disassemble(std::ostream& stream) const {
		disassemble_hex(stream, static_cast<std::uint16_t>(get_cpu()->get_registers().PC - LEN));
		stream << ": ";
		disassemble_hex(stream, OPCODE);
		stream << " ";
	}
};

template<std::uint8_t OP, std::uint_fast64_t CYCLES>
class mos_6510_nullary_instruction : public mos_6510_instruction<OP, 1, CYCLES> {
public:
	void disassemble(std::ostream& stream) const {
		mos_disassemble(stream, "");
	}

protected:
	void mos_disassemble(std::ostream& stream, const std::string& mnemonic) const {
		mos_6510_instruction<OP, 1, CYCLES>::mos_disassemble(stream);
		stream << "         " << mnemonic;
	}
};

template<std::uint8_t OP, typename OPERAND, std::uint_fast64_t CYCLES>
class mos_6510_unary_instruction : public mos_6510_instruction<OP, 1+sizeof(OPERAND), CYCLES> {
public:
	void decode() {
		this->get_cpu()->get_decoder()->get_program_code(_operand, 1);
	}

	void disassemble(std::ostream& stream) const {
		mos_disassemble(stream, "");
	}

protected:
	void disassemble_operand(std::ostream& stream, std::uint8_t operand) const {
		disassemble_hex(stream, operand);
		stream << "   ";
	}

	void disassemble_operand(std::ostream& stream, std::uint16_t operand) const {
		disassemble_hex(stream, static_cast<std::uint8_t>(operand & 0xff));
		stream << " ";
		disassemble_hex(stream, static_cast<std::uint8_t>((operand >> 8) & 0xff));
	}

	void mos_disassemble(std::ostream& stream, const std::string& mnemonic) const {
		mos_6510_instruction<OP, 1 + sizeof(OPERAND), CYCLES>::mos_disassemble(stream);
		disassemble_operand(stream, _operand);
		stream << "    " << mnemonic << " ";
	}

	void mos_disassemble_immediate(std::ostream& stream, const std::string& mnemonic) const {
		mos_disassemble(stream, mnemonic);
		stream << "#$";
		disassemble_hex(stream, _operand);
	}

	void mos_disassemble_absolute(std::ostream& stream, const std::string& mnemonic) const {
		mos_disassemble(stream, mnemonic);
		stream << "$";
		disassemble_hex(stream, _operand);
	}

	void mos_disassemble_absolute_x(std::ostream& stream, const std::string& mnemonic) const {
		mos_disassemble(stream, mnemonic);
		stream << "$";
		disassemble_hex(stream, _operand);
		stream << ",X";
	}

	void mos_disassemble_relative(std::ostream& stream, const std::string& mnemonic) const {
		mos_disassemble(stream, mnemonic);
		stream << "$";
		disassemble_hex(stream, static_cast<std::uint16_t>(get_cpu()->get_registers().PC + static_cast<std::int8_t>(_operand)));
		stream << " [#$";
		disassemble_hex(stream, _operand);
		stream << "]";
	}

	OPERAND _operand{};
};

}
}
}

#endif

