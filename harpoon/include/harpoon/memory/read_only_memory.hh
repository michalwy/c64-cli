#ifndef HARPOON_MEMORY_READ_ONLY_MEMORY_HH
#define HARPOON_MEMORY_READ_ONLY_MEMORY_HH

#include "harpoon/harpoon.hh"
#include "harpoon/memory/address.hh"
#include "harpoon/memory/exception/write_access_violation.hh"

namespace harpoon {
namespace memory {

template<typename MemoryImplementation>
class read_only_memory : public MemoryImplementation {
public:

	using MemoryImplementation::MemoryImplementation;

	virtual void set(address address, uint8_t value) {
		throw COMPONENT_EXCEPTION(exception::write_access_violation, address);
	}

	virtual ~read_only_memory() {}
};

template<typename MemoryImplementation>
using read_only_memory_ptr = std::shared_ptr<read_only_memory<MemoryImplementation>>;

template<typename MemoryImplementation>
using read_only_memory_weak_ptr = std::weak_ptr<read_only_memory<MemoryImplementation>>;

template<typename MemoryImplementation, typename... Args>
read_only_memory_ptr<MemoryImplementation> make_read_only_memory(Args&&... args) {
	return std::make_shared<read_only_memory<MemoryImplementation>>(std::forward<Args>(args)...);
}

}
}

#endif
