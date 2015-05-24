#ifndef CPU_MOS_6502_HH
#define CPU_MOS_6502_HH

#include "harpoon/execution/processing_unit.hh"
#include "harpoon/execution/basic_register.hh"

namespace commodore {
namespace cpu {

class mos_6502 : public harpoon::execution::processing_unit {
public:
	using harpoon::execution::processing_unit::processing_unit;

	virtual void boot();

	virtual std::uint_fast64_t fetch();
	virtual std::uint_fast64_t execute();

	void log_registers(harpoon::log::message::Level level) const;

	virtual ~mos_6502();

private:

	void init_registers();

	struct {
		harpoon::execution::basic_register<uint8_t> A{};
		harpoon::execution::basic_register<uint8_t> X{};
		harpoon::execution::basic_register<uint8_t> Y{};
		harpoon::execution::basic_register<uint8_t> S{};
		harpoon::execution::basic_register<uint16_t> PC{};
	} _registers;
};

}
}

#endif

