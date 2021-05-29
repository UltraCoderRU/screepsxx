#include "RoomPosition.hpp"

#include "RoomObject.hpp"

#include <iostream>

namespace Screeps {

RoomPosition::RoomPosition(JS::Value value) : Object(std::move(value))
{
}

RoomPosition::RoomPosition(const std::string& roomName, int x, int y)
    : Object(JS::getGlobal("RoomPosition").new_(x, y, roomName))
{
}

std::string RoomPosition::roomName() const
{
	return value()["roomName"].as<std::string>();
}

void RoomPosition::setRoomName(const std::string& name)
{
	value().set("roomName", name);
}

int RoomPosition::x() const
{
	return value()["x"].as<int>();
}

void RoomPosition::setX(int x)
{
	value().set("x", x);
}

int RoomPosition::y() const
{
	return value()["y"].as<int>();
}

void RoomPosition::setY(int y)
{
	value().set("y", y);
}

std::unique_ptr<RoomObject>
RoomPosition::findClosestByPath(const std::vector<std::unique_ptr<RoomObject>>& objects)
{
	std::vector<JS::Value> values;
	values.reserve(objects.size());
	for (const auto& object : objects)
		values.push_back(object->value());

	auto object = findClosestByPath(values);
	if (object)
		return createRoomObject(std::move(*object));
	else
		return nullptr;
}

std::optional<JS::Value> RoomPosition::findClosestByPath(const std::vector<JS::Value>& objects)
{
	auto array = JS::vectorToJSArray(objects);
	auto object = value().call<JS::Value>("findClosestByPath", array);
	if (object.isUndefined())
		return std::nullopt;
	else
		return object;
}

} // namespace Screeps
