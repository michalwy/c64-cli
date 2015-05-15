#include "harpoon/clock/generator/threaded_generator.hh"

using namespace harpoon::clock::generator;

threaded_generator::~threaded_generator() {}

void threaded_generator::start() {

	uint32_t delay = 1000000000 / get_frequency();

	set_tick(0);

	_running = true;
	_thread.reset(new std::thread([this, delay] {
		while (is_running()) {
			tick();
			std::this_thread::sleep_for(std::chrono::nanoseconds(delay));
		}
	}));
}

void threaded_generator::stop() {
	_running = false;
	if (_thread) {
		_thread->join();
		_thread.reset(nullptr);
	}
}

