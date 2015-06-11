#include "qt_log.hh"

using namespace commodore::ui;

qt_log::~qt_log() {
	delete _emitter;
}

void qt_log::out(const harpoon::log::message& message) {
	_emitter->emit_signal(message);
}
