#include "Room.hpp"

#include "Creep.hpp"
#include "JSON.hpp"
#include "StructureController.hpp"
#include "StructureStorage.hpp"

#include <iostream>

namespace Screeps {

Room::Room(JS::Value value) : Object(std::move(value))
{
}

std::optional<StructureController> Room::controller() const
{
	if (value()["controller"].isUndefined())
		return std::nullopt;
	return StructureController(value()["controller"]);
}

int Room::energyAvailable() const
{
	return value()["energyAvailable"].as<int>();
}

int Room::energyCapacityAvailable() const
{
	return value()["energyCapacityAvailable"].as<int>();
}

JSON Room::memory() const
{
	return JS::toJSON(value()["memory"]);
}

void Room::setMemory(const JSON& memory)
{
	value().set("memory", JS::fromJSON(memory));
}

std::string Room::name() const
{
	return value()["name"].as<std::string>();
}

std::optional<StructureStorage> Room::storage() const
{
	if (value()["storage"].isUndefined())
		return std::nullopt;
	return StructureStorage(value()["storage"]);
}

std::vector<std::unique_ptr<RoomObject>>
Room::find(int type, std::function<bool(const JS::Value&)> predicate) const
{
	std::vector<std::unique_ptr<RoomObject>> list;

	std::vector<JS::Value> objects = JS::jsArrayToVector(value().call<JS::Value>("find", type));
	if (predicate)
		objects.erase(std::remove_if(objects.begin(), objects.end(),
		                             [predicate](const JS::Value& value)
		                             { return !predicate(value); }),
		              objects.end());

	for (auto& object : objects)
	{
		if (auto roomObject = createRoomObject(object))
			list.push_back(std::move(roomObject));
		else
			JS::console.log(std::string("failed to create RoomObject from "),
			                JS::getGlobal("JSON").call<std::string>("stringify", object));
	}

	return list;
}

int Room::findExitTo(const std::string& room)
{
	return value().call<int>("findExitTo", room);
}

} // namespace Screeps
