#include "Store.hpp"

namespace Screeps {

Store::Store(JS::Value value) : Object(std::move(value))
{
}

std::optional<int>
getCapacity(JS::Value& store, const char* method, const std::optional<std::string>& resource)
{
	JS::Value capacity =
	    resource ? store.call<JS::Value>(method, *resource) : store.call<JS::Value>(method);
	if (capacity.isUndefined())
		return std::nullopt;
	else
		return capacity.as<int>();
}

std::optional<int> Store::getCapacity(const std::optional<std::string>& resource)
{
	return Screeps::getCapacity(value(), "getCapacity", *resource);
}

std::optional<int> Store::getFreeCapacity(const std::optional<std::string>& resource)
{
	return Screeps::getCapacity(value(), "getFreeCapacity", *resource);
}

std::optional<int> Store::getUsedCapacity(const std::optional<std::string>& resource)
{
	return Screeps::getCapacity(value(), "getUsedCapacity", *resource);
}

int Store::operator[](const std::string& resource)
{
	return *getUsedCapacity(resource);
}

} // namespace Screeps
