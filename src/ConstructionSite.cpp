#include "ConstructionSite.hpp"

namespace Screeps {

ConstructionSite::ConstructionSite(JS::Value value) : RoomObject(std::move(value))
{
}

std::string ConstructionSite::id() const
{
	return value()["id"].as<std::string>();
}

bool ConstructionSite::my() const
{
	return value()["my"].as<bool>();
}

std::string ConstructionSite::owner() const
{
	return value()["owner"]["username"].as<std::string>();
}

int ConstructionSite::progress() const
{
	return value()["progress"].as<int>();
}

int ConstructionSite::progressTotal() const
{
	return value()["progressTotal"].as<int>();
}

std::string ConstructionSite::structureType() const
{
	return value()["structureType"].as<std::string>();
}

int ConstructionSite::remove()
{
	return value().call<int>("remove");
}

} // namespace Screeps
