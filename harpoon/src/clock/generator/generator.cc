#include "harpoon/clock/generator/generator.hh"

namespace harpoon {
namespace clock {
namespace generator {

generator::~generator() {}

void generator::start() {
	_running = true;
	_tick = 0;
}

void generator::stop() {
	_running = false;
}

}
}
}
