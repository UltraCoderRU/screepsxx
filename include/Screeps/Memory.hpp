#ifndef SCREEPS_MEMORY_HPP
#define SCREEPS_MEMORY_HPP

#include "Object.hpp"

#include <string_view>

namespace Screeps {

class MemoryObject : public Object
{
public:
	MemoryObject();

	JSON operator[](const std::string_view& key);
	void set(const std::string_view& key, const JSON& value);
};

extern MemoryObject Memory;

} // namespace Screeps

#endif // SCREEPS_MEMORY_HPP
