#include "harpoon/log/message.hh"

#include <sstream>

using namespace harpoon::log;

message::~message() {}

std::string message::get_text() const {
	return _streambuf.str();
}
