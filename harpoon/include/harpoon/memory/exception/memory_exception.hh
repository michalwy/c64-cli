#ifndef HARPOON_MEMORY_EXCEPTION_MEMORY_EXCEPTION_HH
#define HARPOON_MEMORY_EXCEPTION_MEMORY_EXCEPTION_HH

#include "harpoon/harpoon.hh"
#include "harpoon/exception/hardware_component_exception.hh"

namespace harpoon {
namespace memory {
namespace exception {

class memory_exception : public harpoon::exception::hardware_component_exception {
public:

	using harpoon::exception::hardware_component_exception::hardware_component_exception;

	virtual ~memory_exception();

};

}
}
}

#endif