#include "StructureStorage.hpp"

#include "Store.hpp"

namespace Screeps {

StructureStorage::StructureStorage(JS::Value value) : OwnedStructure(std::move(value))
{
}

Store StructureStorage::store() const
{
	return Store(value()["store"]);
}

} // namespace Screeps
