#include "Flag.hpp"

#include "JSON.hpp"
#include "RoomPosition.hpp"

namespace Screeps {

Flag::Flag(JS::Value value) : RoomObject(std::move(value))
{
}

int Flag::color() const
{
	return value()["color"].as<int>();
}

JSON Flag::memory() const
{
	return JS::toJSON(value()["memory"]);
}

void Flag::setMemory(const JSON& memory)
{
	value().set("memory", JS::fromJSON(memory));
}

std::string Flag::name() const
{
	return value()["name"].as<std::string>();
}

int Flag::secondaryColor() const
{
	return value()["secondaryColor"].as<int>();
}

void Flag::remove()
{
	value().call<void>("remove");
}

int Flag::setColor(int color, const std::optional<int>& secondaryColor)
{
	if (secondaryColor)
		return value().call<int>("setColor", color, *secondaryColor);
	else
		return value().call<int>("setColor", color);
}

int Flag::setPosition(int x, int y)
{
	return value().call<int>("setPosition", x, y);
}

int Flag::setPosition(const RoomPosition& pos)
{
	return value().call<int>("setPosition", pos.value());
}

int Flag::setPosition(const RoomObject& pos)
{
	return value().call<int>("setPosition", pos.value());
}

} // namespace Screeps
