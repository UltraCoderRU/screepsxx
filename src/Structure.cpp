#include "Structure.hpp"

#include "Effect.hpp"
#include "Room.hpp"
#include "RoomPosition.hpp"

namespace Screeps {

Structure::Structure(JS::Value value) : RoomObject(std::move(value))
{
}

int Structure::hits() const
{
	if (value()["hits"].isUndefined())
		return std::numeric_limits<int>::max();
	return value()["hits"].as<int>();
}

int Structure::hitsMax() const
{
	if (value()["hitsMax"].isUndefined())
		return std::numeric_limits<int>::max();
	return value()["hitsMax"].as<int>();
}

std::string Structure::id() const
{
	return value()["id"].as<std::string>();
}

std::string Structure::structureType() const
{
	return value()["structureType"].as<std::string>();
}

int Structure::destroy()
{
	return value().call<int>("destroy");
}

bool Structure::isActive()
{
	return value().call<bool>("isActive");
}

int Structure::notifyWhenAttacked(bool enabled)
{
	return value().call<int>("notifyWhenAttacked", enabled);
}

} // namespace Screeps
