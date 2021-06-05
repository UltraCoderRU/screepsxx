#ifndef SCREEPS_RESOURCE_HPP
#define SCREEPS_RESOURCE_HPP

#include "RoomObject.hpp"

namespace Screeps {

class Resource : public RoomObject
{
public:
	explicit Resource(JS::Value value);

	int amount() const;

	std::string id() const;

	std::string resourceType() const;
};

} // namespace Screeps

#endif // SCREEPS_RESOURCE_HPP
