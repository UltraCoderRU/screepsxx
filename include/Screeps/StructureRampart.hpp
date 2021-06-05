#ifndef SCREEPS_STRUCTURE_RAMPART_HPP
#define SCREEPS_STRUCTURE_RAMPART_HPP

#include "Structure.hpp"

namespace Screeps {

class StructureRampart : public Structure
{
public:
	explicit StructureRampart(JS::Value value);

	bool isPublic() const;

	int ticksToDecay() const;

	int setPublic(bool isPublic);
};

} // namespace Screeps

#endif // SCREEPS_STRUCTURE_RAMPART_HPP
