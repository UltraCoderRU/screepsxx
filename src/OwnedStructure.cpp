#include "OwnedStructure.hpp"

namespace Screeps {

OwnedStructure::OwnedStructure(JS::Value value) : Structure(std::move(value))
{
}

bool OwnedStructure::my() const
{
	return value()["my"].as<bool>();
}

std::string OwnedStructure::owner() const
{
	return value()["owner"]["username"].as<std::string>();
}

} // namespace Screeps
