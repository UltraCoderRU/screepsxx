#ifndef SCREEPS_OWNED_STRUCTURE_HPP
#define SCREEPS_OWNED_STRUCTURE_HPP

#include "Structure.hpp"

namespace Screeps {

class OwnedStructure : public Structure
{
public:
	explicit OwnedStructure(JS::Value value);

	bool my() const;

	std::string owner() const;
};

} // namespace Screeps

#endif // SCREEPS_OWNED_STRUCTURE_HPP
