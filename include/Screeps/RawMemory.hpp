#ifndef SCREEPS_RAW_MEMORY_HPP
#define SCREEPS_RAW_MEMORY_HPP

#include "Object.hpp"

namespace Screeps {

class RawMemoryObject : public Object
{
public:
	RawMemoryObject();
};

extern RawMemoryObject RawMemory;

} // namespace Screeps

#endif // SCREEPS_RAW_MEMORY_HPP
