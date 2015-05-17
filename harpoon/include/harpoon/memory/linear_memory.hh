#ifndef HARPOON_MEMORY_LINEAR_MEMORY_HH
#define HARPOON_MEMORY_LINEAR_MEMORY_HH

#include "harpoon/harpoon.hh"
#include "harpoon/memory/memory.hh"

#include <array>

namespace harpoon {
namespace memory {

class linear_memory : public memory {
public:

	using memory::memory;

	virtual void prepare();

	virtual void get(address address, uint8_t& value);
	virtual void set(address address, uint8_t value);

	virtual ~linear_memory();

private:
	std::unique_ptr<std::uint8_t[]> _memory{};
};

}
}

#endif