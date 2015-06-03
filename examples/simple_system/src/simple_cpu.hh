#ifndef SIMPLE_CPU_HH
#define SIMPLE_CPU_HH

#include "harpoon/execution/processing_unit.hh"
#include "harpoon/execution/basic_register.hh"

class simple_cpu : public harpoon::execution::processing_unit {
public:
	using harpoon::execution::processing_unit::processing_unit;

	virtual std::uint_fast64_t begin_execution();
	virtual std::uint_fast64_t fetch_decode(harpoon::execution::instruction_handler& instruction_handler);

	virtual ~simple_cpu();

private:
	struct {
		harpoon::execution::basic_register<uint8_t> A{};
		harpoon::execution::basic_register<uint8_t> X{};
		harpoon::execution::basic_register<uint8_t> Y{};
		harpoon::execution::basic_register<uint8_t> S{};
		harpoon::execution::basic_register<uint16_t> PC{};
	} _registers;
};

#endif

