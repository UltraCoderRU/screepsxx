#include "Resource.hpp"

namespace Screeps {

Resource::Resource(JS::Value value) : RoomObject(std::move(value))
{
}

int Resource::amount() const
{
	return value()["amount"].as<int>();
}

std::string Resource::id() const
{
	return value()["id"].as<std::string>();
}

std::string Resource::resourceType() const
{
	return value()["resourceType"].as<std::string>();
}

} // namespace Screeps
