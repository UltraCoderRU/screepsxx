#ifndef SCREEPS_STRUCTURE_EXTRACTOR_HPP
#define SCREEPS_STRUCTURE_EXTRACTOR_HPP

#include "OwnedStructure.hpp"

namespace Screeps {

class StructureExtractor : public OwnedStructure
{
public:
	explicit StructureExtractor(JS::Value value);

	int cooldown() const;
};

} // namespace Screeps

#endif // SCREEPS_STRUCTURE_EXTRACTOR_HPP
