#ifndef SCREEPS_STORE_HPP
#define SCREEPS_STORE_HPP

#include "Object.hpp"

#include <optional>

namespace Screeps {

class Store : public Object
{
public:
	explicit Store(JS::Value value);

	std::optional<int> getCapacity(const std::optional<std::string>& resource = std::nullopt);

	std::optional<int> getFreeCapacity(const std::optional<std::string>& resource = std::nullopt);

	std::optional<int> getUsedCapacity(const std::optional<std::string>& resource = std::nullopt);

	int operator[](const std::string& resource);
};

} // namespace Screeps

#endif // SCREEPS_STORE_HPP
