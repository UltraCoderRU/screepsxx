#ifndef SCREEPS_STRUCTURE_TERMINAL_HPP
#define SCREEPS_STRUCTURE_TERMINAL_HPP

#include "OwnedStructure.hpp"
#include "Store.hpp"

#include <optional>

namespace Screeps {

class StructureTerminal : public OwnedStructure
{
public:
	explicit StructureTerminal(JS::Value value);

	int cooldown() const;

	Store store() const;

	int send(const std::string& resourceType,
	         int amount,
	         const std::string& destination,
	         const std::optional<std::string>& description = std::nullopt);
};

} // namespace Screeps

#endif // SCREEPS_STRUCTURE_TERMINAL_HPP
