#include "Game.hpp"

#include "ConstructionSite.hpp"
#include "Creep.hpp"
#include "Room.hpp"
#include "StructureSpawn.hpp"

namespace Screeps {

GameObject Game;

GameObject::GameObject() = default;

template <class T>
typename std::enable_if_t<std::is_base_of<Object, T>::value, std::map<std::string, T>>
convertObjectToMap(const JS::Value& object)
{
	std::map<std::string, T> map;
	for (const auto& pair : JS::jsObjectToMap(object))
		map.insert(std::make_pair(pair.first, T{pair.second}));
	return map;
}

template <class T>
typename std::enable_if_t<!std::is_base_of<Object, T>::value, std::map<std::string, T>>
convertObjectToMap(const JS::Value& object)
{
	std::map<std::string, T> map;
	for (const auto& pair : JS::jsObjectToMap(object))
		map.emplace(pair.first, pair.second.as<T>());
	return map;
}

std::map<std::string, ConstructionSite> GameObject::constructionSites() const
{
	return convertObjectToMap<ConstructionSite>(value()["constructionSites"]);
}

JSON GameObject::cpu() const
{
	return JS::toJSON(value()["cpu"]);
}

std::map<std::string, Creep> GameObject::creeps() const
{
	return convertObjectToMap<Creep>(value()["creeps"]);
}

GameObject::GCL GameObject::gcl() const
{
	GCL gcl;

	auto obj = value()["gcl"];
	gcl.level = obj["level"].as<int>();
	gcl.progress = obj["progress"].as<int>();
	gcl.progressTotal = obj["progressTotal"].as<int>();

	return gcl;
}

GameObject::GPL GameObject::gpl() const
{
	GPL gpl;

	auto obj = value()["gpl"];
	gpl.level = obj["level"].as<int>();
	gpl.progress = obj["progress"].as<int>();
	gpl.progressTotal = obj["progressTotal"].as<int>();

	return gpl;
}

std::map<std::string, int> GameObject::resources() const
{
	return convertObjectToMap<int>(value()["resources"]);
}

std::map<std::string, Room> GameObject::rooms() const
{
	return convertObjectToMap<Room>(value()["rooms"]);
}

GameObject::Shard GameObject::shard() const
{
	Shard shard;

	auto obj = value()["shard"];
	shard.name = obj["name"].as<std::string>();
	shard.type = obj["type"].as<std::string>();
	shard.ptr = obj["ptr"].as<bool>();

	return shard;
}

std::map<std::string, StructureSpawn> GameObject::spawns() const
{
	return convertObjectToMap<StructureSpawn>(value()["spawns"]);
}

std::map<std::string, Structure> GameObject::structures() const
{
	return convertObjectToMap<Structure>(value()["structures"]);
}

int GameObject::time() const
{
	return value()["time"].as<int>();
}

double GameObject::cpuGetUsed()
{
	return value()["cpu"].call<double>("getUsed");
}

int GameObject::cpuGeneratePixel()
{
	return value()["cpu"].call<int>("generatePixel");
}

std::unique_ptr<RoomObject> GameObject::getObjectById(const std::string& id)
{
	auto object = value().call<JS::Value>("getObjectById", id);
	if (object.isUndefined())
		return nullptr;
	else
		return createRoomObject(std::move(object));
}

} // namespace Screeps
