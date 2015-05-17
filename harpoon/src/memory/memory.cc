#include "harpoon/memory/memory.hh"

using namespace harpoon::memory;

memory::~memory() {}

void memory::add_memory_block(const memory_weak_ptr& memory_block, bool owner) {
	if (owner) {
		add_component(memory_block);
	}
	_memory_blocks.push_back(memory_block);
}
