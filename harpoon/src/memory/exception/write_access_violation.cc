#include "harpoon/memory/exception/write_access_violation.hh"

#include <sstream>
#include <iomanip>

using namespace harpoon::memory::exception;

write_access_violation::write_access_violation(const std::string& component,
											   harpoon::memory::address address,
											   const std::string& file,
											   int line,
											   const std::string& function)
	: access_violation(component, address, file, line, function) {
	std::stringstream stream;
	stream
		<< "Memory write access violation at 0x"
		<< std::setfill('0') << std::setw(sizeof(address) * 2) << std::hex << address;
	set_what(stream.str());
}

write_access_violation::~write_access_violation() {}
