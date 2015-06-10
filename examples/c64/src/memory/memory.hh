#ifndef MEMORY_MEMORY_HH
#define MEMORY_MEMORY_HH

#include "harpoon/memory/main_memory.hh"

namespace commodore {
namespace memory {

class memory : public harpoon::memory::main_memory {
public:

	using harpoon::memory::main_memory::main_memory;

	void create();

	virtual void prepare();

	virtual void shutdown();

	virtual void get(harpoon::memory::address address, std::uint8_t& value);
	virtual void set(harpoon::memory::address address, std::uint8_t value);

	virtual ~memory();

private:

	void load_kernal();
	void load_basic();

	harpoon::memory::memory_weak_ptr _read_memory{};
	harpoon::memory::memory_weak_ptr _write_memory{};

	harpoon::memory::memory_weak_ptr _basic_a000_bfff{};
	harpoon::memory::memory_weak_ptr _kernal_e000_ffff{};
	harpoon::memory::memory_weak_ptr _ram_0000_3fff{};
	harpoon::memory::memory_weak_ptr _ram_4000_7fff{};
	harpoon::memory::memory_weak_ptr _ram_d000_dfff{};
	harpoon::memory::memory_weak_ptr _ram_e000_ffff{};
};

}
}

#endif

