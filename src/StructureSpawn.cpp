#include "StructureSpawn.hpp"

#include "JSON.hpp"
#include "Store.hpp"

namespace Screeps {

StructureSpawn::StructureSpawn(JS::Value obj) : OwnedStructure(std::move(obj))
{
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

} // namespace Screeps
