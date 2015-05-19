#ifndef HARPOON_MEMORY_MEMORY_HH
#define HARPOON_MEMORY_MEMORY_HH

#include "harpoon/harpoon.hh"
#include "harpoon/hardware_component.hh"
#include "harpoon/memory/address_range.hh"

#include <list>

namespace harpoon {
namespace memory {

class memory;

using memory_ptr = std::shared_ptr<memory>;
using memory_weak_ptr = std::weak_ptr<memory>;

class memory : public hardware_component {
public:

	memory(const std::string& name = {}, const address_range& address_range = {})
		: hardware_component(name), _address_range(address_range) {}

	const address_range& get_address_range() const {
		return _address_range;
	}

	address_range& get_address_range() {
		return _address_range;
	}

	void set_address_range(const address_range& range) {
		_address_range = range;
	}

	bool has_address(address address) const {
		return get_address_range().has_address(address);
	}

	virtual void get(address address, uint8_t& value) = 0;

	virtual void set(address address, uint8_t value) = 0;

	virtual ~memory();

private:
	address_range _address_range{};
};

}
}

#endif

