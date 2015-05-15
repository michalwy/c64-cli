#include "harpoon/execution/up_execution_unit.hh"

using namespace harpoon::execution;

void up_execution_unit::cleanup() {
	_cpu.reset();
	execution_unit::cleanup();
}