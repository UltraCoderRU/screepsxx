#include "StructureSpawn.hpp"

#include "Creep.hpp"
#include "JSON.hpp"
#include "Store.hpp"

namespace Screeps {

StructureSpawn::StructureSpawn(JS::Value obj) : OwnedStructure(std::move(obj))
{
}

JSON StructureSpawn::memory() const
{
	return JS::toJSON(value()["memory"]);
}

void StructureSpawn::setMemory(const JSON& memory)
{
	value().set("memory", JS::fromJSON(memory));
}

std::optional<StructureSpawn::Spawning> StructureSpawn::spawning() const
{
	auto obj = value()["spawning"];
	if (obj.isUndefined())
		return std::nullopt;
	else
		return Spawning(std::move(obj));
}

Store StructureSpawn::store() const
{
	return Store(value()["store"]);
}

std::string StructureSpawn::name() const
{
	return value()["name"].as<std::string>();
}

int StructureSpawn::spawnCreep(const std::vector<std::string>& body, const std::string& name)
{
	JSON bodyArray = JSON::array();
	std::copy(body.begin(), body.end(), std::back_inserter(bodyArray));
	return value().call<int>("spawnCreep", JS::vectorToJSArray(body), name);
}

int StructureSpawn::spawnCreep(const std::vector<std::string>& body,
                               const std::string& name,
                               const JSON& options)
{
	JSON bodyArray = JSON::array();
	std::copy(body.begin(), body.end(), std::back_inserter(bodyArray));
	return value().call<int>("spawnCreep", JS::vectorToJSArray(body), name, JS::fromJSON(options));
}

int StructureSpawn::recycleCreep(const Creep& target)
{
	return value().call<int>("recycleCreep", target.value());
}

int StructureSpawn::renewCreep(const Creep& target)
{
	return value().call<int>("renewCreep", target.value());
}

StructureSpawn::Spawning::Spawning(JS::Value value) : Object(std::move(value))
{
}

std::vector<int> StructureSpawn::Spawning::directions() const
{
	return JS::jsArrayToVector<int>(value()["directions"]);
}

std::string StructureSpawn::Spawning::name() const
{
	return value()["name"].as<std::string>();
}

int StructureSpawn::Spawning::needTime() const
{
	return value()["needTime"].as<int>();
}

int StructureSpawn::Spawning::remainingTime() const
{
	return value()["remainingTime"].as<int>();
}

StructureSpawn StructureSpawn::Spawning::spawn()
{
	return StructureSpawn(value()["spawn"]);
}

int StructureSpawn::Spawning::cancel()
{
	return value().call<int>("cancel");
}

int StructureSpawn::Spawning::setDirections(const std::vector<int>& directions)
{
	return value().call<int>("setDirections", JS::vectorToJSArray(directions));
}

} // namespace Screeps
