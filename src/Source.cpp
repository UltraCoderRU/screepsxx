#include "Source.hpp"

namespace Screeps {

Source::Source(JS::Value value) : RoomObject(std::move(value))
{
}

int Source::energy() const
{
	return value()["energy"].as<int>();
}

int Source::energyCapacity() const
{
	return value()["energyCapacity"].as<int>();
}

std::string Source::id() const
{
	return value()["id"].as<std::string>();
}

int Source::ticksToLive() const
{
	return value()["ticksToLive"].as<int>();
}

} // namespace Screeps
