#ifndef HARPOON_EXECUTION_CPU_HH
#define HARPOON_EXECUTION_CPU_HH

#include "harpoon/harpoon.hh"
#include "harpoon/hardware_component.hh"

namespace harpoon {
namespace execution {

class cpu : public hardware_component {
public:

	using hardware_component::hardware_component;

	virtual ~cpu();
};

using cpu_ptr = std::shared_ptr<cpu>;
using cpu_weak_ptr = std::weak_ptr<cpu>;
}
}

#endif