#ifndef SCREEPS_STRUCTURE_EXTENSION_HPP
#define SCREEPS_STRUCTURE_EXTENSION_HPP

#include "Structure.hpp"

namespace Screeps {

class Store;

class StructureExtension : public Structure
{
public:
	explicit StructureExtension(JS::Value value);

	Store store() const;
};

} // namespace Screeps

#endif // SCREEPS_STRUCTURE_EXTENSION_HPP
