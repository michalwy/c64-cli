#ifndef CPU_MOS_6510_FLAGS_HH
#define CPU_MOS_6510_FLAGS_HH

#include "harpoon/execution/basic_register.hh"

#include <bitset>

namespace commodore {
namespace cpu {

class mos_6510_flags : public harpoon::execution::basic_register<std::bitset<8>> {
public:

	bool N() const {
		return get()[7];
	}

	std::bitset<8>::reference N() {
		return get()[7];
	}

	bool V() const {
		return get()[6];
	}

	std::bitset<8>::reference V() {
		return get()[6];
	}

	bool B() const {
		return get()[4];
	}

	std::bitset<8>::reference B() {
		return get()[4];
	}

	bool D() const {
		return get()[3];
	}

	std::bitset<8>::reference D() {
		return get()[3];
	}

	bool I() const {
		return get()[2];
	}

	std::bitset<8>::reference I() {
		return get()[2];
	}

	bool Z() const {
		return get()[1];
	}

	std::bitset<8>::reference Z() {
		return get()[1];
	}

	bool C() const {
		return get()[0];
	}

	std::bitset<8>::reference C() {
		return get()[0];
	}

};

}
}

#endif

