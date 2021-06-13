#include "Memory.hpp"

#include <Screeps/JSON.hpp>

namespace Screeps {

MemoryObject Memory;

MemoryObject::MemoryObject() = default;

JSON MemoryObject::operator[](const std::string_view& key)
{
	return JS::toJSON(value()[key.data()]);
}

void MemoryObject::set(const std::string_view& key, const JSON& value)
{
	this->value().set(key.data(), JS::fromJSON(value));
}

} // namespace Screeps
