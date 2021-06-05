#include "StructureExtension.hpp"

#include "Store.hpp"

namespace Screeps {

StructureExtension::StructureExtension(JS::Value value) : Structure(std::move(value))
{
}

Store StructureExtension::store() const
{
	return Store(value()["store"]);
}

} // namespace Screeps
