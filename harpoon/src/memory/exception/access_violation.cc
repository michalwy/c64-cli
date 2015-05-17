#include "harpoon/memory/exception/access_violation.hh"

#include <sstream>
#include <iomanip>

using namespace harpoon::memory::exception;

access_violation::access_violation(const std::string& component,
								   harpoon::memory::address address,
								   const std::string& file,
								   uint32_t line,
								   const std::string& function)
	: memory_exception(component, "", file, line, function), _address(address) {
	std::stringstream stream;
	stream
		<< "Memory access violation at 0x"
		<< std::setfill('0') << std::setw(sizeof(address) * 2) << std::hex << address;
	set_what(stream.str());
}

access_violation::~access_violation() {}
