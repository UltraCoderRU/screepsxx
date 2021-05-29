#ifndef SPAWN_HPP
#define SPAWN_HPP

#include "OwnedStructure.hpp"

namespace Screeps {

class Store;

class StructureSpawn : public OwnedStructure
{
public:
	explicit StructureSpawn(JS::Value obj);

	Store store() const;

	std::string name() const;


	int spawnCreep(const std::vector<std::string>& body, const std::string& name);
	int spawnCreep(const std::vector<std::string>& body, const std::string& name, const JSON& options);
};

} // namespace Screeps

#endif // SPAWN_HPP
