#ifndef HARPOON_EXECUTION_EXECUTION_UNIT_HH
#define HARPOON_EXECUTION_EXECUTION_UNIT_HH

#include "harpoon/harpoon.hh"
#include "harpoon/hardware_component.hh"

#include <memory>

namespace harpoon {
namespace execution {

class execution_unit : public hardware_component {
public:

	using hardware_component::hardware_component;

	virtual ~execution_unit();
};

using execution_unit_ptr = std::shared_ptr<execution_unit>;
using execution_unit_weak_ptr = std::weak_ptr<execution_unit>;

}
}

#endif