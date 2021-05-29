#ifndef SCREEPS_MEMORY_HPP
#define SCREEPS_MEMORY_HPP

#include "Object.hpp"

namespace Screeps {

class MemoryObject : public Object
{
public:
	MemoryObject();
};

extern MemoryObject Memory;

} // namespace Screeps

#endif // SCREEPS_MEMORY_HPP
