#ifndef SCREEPS_STRUCTURE_SPAWN_HPP
#define SCREEPS_STRUCTURE_SPAWN_HPP

#include "OwnedStructure.hpp"

#include <optional>

namespace Screeps {

class Creep;
class Store;

class StructureSpawn : public OwnedStructure
{
public:
	class Spawning;

	explicit StructureSpawn(JS::Value obj);

	JSON memory() const;
	void setMemory(const JSON&);

	std::string name() const;

	std::optional<Spawning> spawning() const;

	Store store() const;

	int spawnCreep(const std::vector<std::string>& body, const std::string& name);
	int spawnCreep(const std::vector<std::string>& body, const std::string& name, const JSON& options);

	int recycleCreep(const Creep& target);

	int renewCreep(const Creep& target);
};

class StructureSpawn::Spawning : public Object
{
public:
	explicit Spawning(JS::Value value);

	std::vector<int> directions() const;

	std::string name() const;

	int needTime() const;

	int remainingTime() const;

	StructureSpawn spawn();

	int cancel();

	int setDirections(const std::vector<int>& directions);
};

} // namespace Screeps

#endif // SCREEPS_STRUCTURE_SPAWN_HPP
