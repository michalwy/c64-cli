#ifndef CPU_INSTRUCTIONS_CMP_HH
#define CPU_INSTRUCTIONS_CMP_HH

#include "mos_6510_instruction.hh"

namespace commodore {
namespace cpu {
namespace instructions {

class cmp_absolute_x : public mos_6510_unary_instruction<0xDD, std::uint16_t, 4> {
public:
	void execute() {
		std::uint8_t mem{}, a{};
		get_cpu()->get_memory()->get(_operand + get_cpu()->get_registers().X, mem);
		a = get_cpu()->get_registers().A;
		get_cpu()->get_registers().P.Z() = (a == mem);
	}
};

}
}
}

#endif

