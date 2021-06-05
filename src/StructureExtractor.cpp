#include "StructureExtractor.hpp"

namespace Screeps {

StructureExtractor::StructureExtractor(JS::Value value) : OwnedStructure(std::move(value))
{
}

int StructureExtractor::cooldown() const
{
	return value()["cooldown"].as<int>();
}

} // namespace Screeps
