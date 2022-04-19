#ifndef SCREEPS_STRUCTURE_LINK_HPP
#define SCREEPS_STRUCTURE_LINK_HPP

#include "OwnedStructure.hpp"

namespace Screeps {

class Store;

class StructureLink : public OwnedStructure
{
public:
	explicit StructureLink(JS::Value value);

	int cooldown() const;

	Store store() const;

	int transferEnergy(const StructureLink& target, const std::optional<int>& amount = std::nullopt);
};

} // namespace Screeps

#endif // SCREEPS_STRUCTURE_LINK_HPP
