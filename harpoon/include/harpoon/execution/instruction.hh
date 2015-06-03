#ifndef HARPOON_EXECUTION_INSTRUCTION_HH
#define HARPOON_EXECUTION_INSTRUCTION_HH

#include "harpoon/harpoon.hh"

#include <functional>

namespace harpoon {
namespace execution {

class processing_unit;

using instruction = std::function<std::uint_fast64_t(processing_unit *)>;

}
}

#endif

