#ifndef SCREEPS_STRUCTURE_STORAGE_HPP
#define SCREEPS_STRUCTURE_STORAGE_HPP

#include "OwnedStructure.hpp"

namespace Screeps {

class Store;

class StructureStorage : public OwnedStructure
{
public:
	explicit StructureStorage(JS::Value value);

	Store store() const;
};

} // namespace Screeps

#endif // SCREEPS_STRUCTURE_STORAGE_HPP
