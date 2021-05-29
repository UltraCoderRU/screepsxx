#ifndef SCREEPS_CONSTANTS_HPP
#define SCREEPS_CONSTANTS_HPP

#include <map>
#include <string>
#include <vector>

namespace Screeps {

const int OK = 0;
const int ERR_NOT_OWNER = -1;
const int ERR_NO_PATH = -2;
const int ERR_NAME_EXISTS = -3;
const int ERR_BUSY = -4;
const int ERR_NOT_FOUND = -5;
const int ERR_NOT_ENOUGH_ENERGY = -6;
const int ERR_NOT_ENOUGH_RESOURCES = -6;
const int ERR_INVALID_TARGET = -7;
const int ERR_FULL = -8;
const int ERR_NOT_IN_RANGE = -9;
const int ERR_INVALID_ARGS = -10;
const int ERR_TIRED = -11;
const int ERR_NO_BODYPART = -12;
const int ERR_NOT_ENOUGH_EXTENSIONS = -6;
const int ERR_RCL_NOT_ENOUGH = -14;
const int ERR_GCL_NOT_ENOUGH = -15;

const int FIND_EXIT_TOP = 1;
const int FIND_EXIT_RIGHT = 3;
const int FIND_EXIT_BOTTOM = 5;
const int FIND_EXIT_LEFT = 7;
const int FIND_EXIT = 10;
const int FIND_CREEPS = 101;
const int FIND_MY_CREEPS = 102;
const int FIND_HOSTILE_CREEPS = 103;
const int FIND_SOURCES_ACTIVE = 104;
const int FIND_SOURCES = 105;
const int FIND_DROPPED_RESOURCES = 106;
const int FIND_STRUCTURES = 107;
const int FIND_MY_STRUCTURES = 108;
const int FIND_HOSTILE_STRUCTURES = 109;
const int FIND_FLAGS = 110;
const int FIND_CONSTRUCTION_SITES = 111;
const int FIND_MY_SPAWNS = 112;
const int FIND_HOSTILE_SPAWNS = 113;
const int FIND_MY_CONSTRUCTION_SITES = 114;
const int FIND_HOSTILE_CONSTRUCTION_SITES = 115;
const int FIND_MINERALS = 116;
const int FIND_NUKES = 117;
const int FIND_TOMBSTONES = 118;
const int FIND_POWER_CREEPS = 119;
const int FIND_MY_POWER_CREEPS = 120;
const int FIND_HOSTILE_POWER_CREEPS = 121;
const int FIND_DEPOSITS = 122;
const int FIND_RUINS = 123;

const int TOP = 1;
const int TOP_RIGHT = 2;
const int RIGHT = 3;
const int BOTTOM_RIGHT = 4;
const int BOTTOM = 5;
const int BOTTOM_LEFT = 6;
const int LEFT = 7;
const int TOP_LEFT = 8;

const int COLOR_RED = 1;
const int COLOR_PURPLE = 2;
const int COLOR_BLUE = 3;
const int COLOR_CYAN = 4;
const int COLOR_GREEN = 5;
const int COLOR_YELLOW = 6;
const int COLOR_ORANGE = 7;
const int COLOR_BROWN = 8;
const int COLOR_GREY = 9;
const int COLOR_WHITE = 10;

const auto LOOK_CREEPS = "creep";
const auto LOOK_ENERGY = "energy";
const auto LOOK_RESOURCES = "resource";
const auto LOOK_SOURCES = "source";
const auto LOOK_MINERALS = "mineral";
const auto LOOK_DEPOSITS = "deposit";
const auto LOOK_STRUCTURES = "structure";
const auto LOOK_FLAGS = "flag";
const auto LOOK_CONSTRUCTION_SITES = "constructionSite";
const auto LOOK_NUKES = "nuke";
const auto LOOK_TERRAIN = "terrain";
const auto LOOK_TOMBSTONES = "tombstone";
const auto LOOK_POWER_CREEPS = "powerCreep";
const auto LOOK_RUINS = "ruin";

const std::vector<std::string> OBSTACLE_OBJECT_TYPES = {
    "spawn",           "creep",     "powerCreep", "source",  "mineral", "deposit",    "controller",
    "constructedWall", "extension", "link",       "storage", "tower",   "observer",   "powerSpawn",
    "powerBank",       "lab",       "terminal",   "nuker",   "factory", "invaderCore"};

const auto MOVE = "move";
const auto WORK = "work";
const auto CARRY = "carry";
const auto ATTACK = "attack";
const auto RANGED_ATTACK = "ranged_attack";
const auto TOUGH = "tough";
const auto HEAL = "heal";
const auto CLAIM = "claim";

const std::map<std::string, int> BODYPART_COST = {
    {"move", 50},  {"work", 100},          {"attack", 80}, {"carry", 50},
    {"heal", 250}, {"ranged_attack", 150}, {"tough", 10},  {"claim", 600}};

// WORLD_WIDTH and WORLD_HEIGHT constants are deprecated, please use Game.map.getWorldSize() instead
const auto WORLD_WIDTH = 202;
const auto WORLD_HEIGHT = 202;

const auto CREEP_LIFE_TIME = 1500;
const auto CREEP_CLAIM_LIFE_TIME = 600;
const auto CREEP_CORPSE_RATE = 0.2;
const auto CREEP_PART_MAX_ENERGY = 125;

const auto CARRY_CAPACITY = 50;
const auto HARVEST_POWER = 2;
const auto HARVEST_MINERAL_POWER = 1;
const auto HARVEST_DEPOSIT_POWER = 1;
const auto REPAIR_POWER = 100;
const auto DISMANTLE_POWER = 50;
const auto BUILD_POWER = 5;
const auto ATTACK_POWER = 30;
const auto UPGRADE_CONTROLLER_POWER = 1;
const auto RANGED_ATTACK_POWER = 10;
const auto HEAL_POWER = 12;
const auto RANGED_HEAL_POWER = 4;
const auto REPAIR_COST = 0.01;
const auto DISMANTLE_COST = 0.005;

const auto RAMPART_DECAY_AMOUNT = 300;
const auto RAMPART_DECAY_TIME = 100;
const auto RAMPART_HITS = 1;
const std::map<int, int> RAMPART_HITS_MAX = {{2, 300000},   {3, 1000000},  {4, 3000000},
                                             {5, 10000000}, {6, 30000000}, {7, 100000000},
                                             {8, 300000000}};

const auto ENERGY_REGEN_TIME = 300;
const auto ENERGY_DECAY = 1000;

const auto SPAWN_HITS = 5000;
const auto SPAWN_ENERGY_START = 300;
const auto SPAWN_ENERGY_CAPACITY = 300;
const auto CREEP_SPAWN_TIME = 3;
const auto SPAWN_RENEW_RATIO = 1.2;

const auto SOURCE_ENERGY_CAPACITY = 3000;
const auto SOURCE_ENERGY_NEUTRAL_CAPACITY = 1500;
const auto SOURCE_ENERGY_KEEPER_CAPACITY = 4000;

const auto WALL_HITS = 1;
const auto WALL_HITS_MAX = 300000000;

const auto EXTENSION_HITS = 1000;
const std::map<int, int> EXTENSION_ENERGY_CAPACITY = {{0, 50}, {1, 50}, {2, 50},  {3, 50}, {4, 50},
                                                      {5, 50}, {6, 50}, {7, 100}, {8, 200}};

const auto ROAD_HITS = 5000;
const auto ROAD_WEAROUT = 1;
const auto ROAD_WEAROUT_POWER_CREEP = 100;
const auto ROAD_DECAY_AMOUNT = 100;
const auto ROAD_DECAY_TIME = 1000;

const auto LINK_HITS = 1000;
const auto LINK_HITS_MAX = 1000;
const auto LINK_CAPACITY = 800;
const auto LINK_COOLDOWN = 1;
const auto LINK_LOSS_RATIO = 0.03;

const auto STORAGE_CAPACITY = 1000000;
const auto STORAGE_HITS = 10000;

const auto STRUCTURE_SPAWN = "spawn";
const auto STRUCTURE_EXTENSION = "extension";
const auto STRUCTURE_ROAD = "road";
const auto STRUCTURE_WALL = "constructedWall";
const auto STRUCTURE_RAMPART = "rampart";
const auto STRUCTURE_KEEPER_LAIR = "keeperLair";
const auto STRUCTURE_PORTAL = "portal";
const auto STRUCTURE_CONTROLLER = "controller";
const auto STRUCTURE_LINK = "link";
const auto STRUCTURE_STORAGE = "storage";
const auto STRUCTURE_TOWER = "tower";
const auto STRUCTURE_OBSERVER = "observer";
const auto STRUCTURE_POWER_BANK = "powerBank";
const auto STRUCTURE_POWER_SPAWN = "powerSpawn";
const auto STRUCTURE_EXTRACTOR = "extractor";
const auto STRUCTURE_LAB = "lab";
const auto STRUCTURE_TERMINAL = "terminal";
const auto STRUCTURE_CONTAINER = "container";
const auto STRUCTURE_NUKER = "nuker";
const auto STRUCTURE_FACTORY = "factory";
const auto STRUCTURE_INVADER_CORE = "invaderCore";

const std::map<std::string, int> CONSTRUCTION_COST = {
    {"spawn", 15000},     {"extension", 3000},    {"road", 300},       {"constructedWall", 1},
    {"rampart", 1},       {"link", 5000},         {"storage", 30000},  {"tower", 5000},
    {"observer", 8000},   {"powerSpawn", 100000}, {"extractor", 5000}, {"lab", 50000},
    {"terminal", 100000}, {"container", 5000},    {"nuker", 100000},   {"factory", 100000}};
const auto CONSTRUCTION_COST_ROAD_SWAMP_RATIO = 5;
const auto CONSTRUCTION_COST_ROAD_WALL_RATIO = 150;

const std::map<int, int> CONTROLLER_LEVELS = {{1, 200},     {2, 45000},   {3, 135000},  {4, 405000},
                                              {5, 1215000}, {6, 3645000}, {7, 10935000}};

const std::map<std::string, std::map<int, int>> CONTROLLER_STRUCTURES = {
    {"spawn", {{0, 0}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 2}, {8, 3}}},
    {"extension", {{0, 0}, {1, 0}, {2, 5}, {3, 10}, {4, 20}, {5, 30}, {6, 40}, {7, 50}, {8, 60}}},
    {"link", {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 2}, {6, 3}, {7, 4}, {8, 6}}},
    {"road",
     {{0, 2500}, {1, 2500}, {2, 2500}, {3, 2500}, {4, 2500}, {5, 2500}, {6, 2500}, {7, 2500}, {8, 2500}}},
    {"constructedWall",
     {{1, 0}, {2, 2500}, {3, 2500}, {4, 2500}, {5, 2500}, {6, 2500}, {7, 2500}, {8, 2500}}},
    {"rampart", {{1, 0}, {2, 2500}, {3, 2500}, {4, 2500}, {5, 2500}, {6, 2500}, {7, 2500}, {8, 2500}}},
    {"storage", {{1, 0}, {2, 0}, {3, 0}, {4, 1}, {5, 1}, {6, 1}, {7, 1}, {8, 1}}},
    {"tower", {{1, 0}, {2, 0}, {3, 1}, {4, 1}, {5, 2}, {6, 2}, {7, 3}, {8, 6}}},
    {"observer", {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 1}}},
    {"powerSpawn", {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 1}}},
    {"extractor", {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 1}, {7, 1}, {8, 1}}},
    {"terminal", {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 1}, {7, 1}, {8, 1}}},
    {"lab", {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 3}, {7, 6}, {8, 10}}},
    {"container", {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {6, 5}, {7, 5}, {8, 5}}},
    {"nuker", {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 1}}},
    {"factory", {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 1}, {8, 1}}}};

const std::map<int, int> CONTROLLER_DOWNGRADE = {{1, 20000}, {2, 10000},  {3, 20000},  {4, 40000},
                                                 {5, 80000}, {6, 120000}, {7, 150000}, {8, 200000}};
const auto CONTROLLER_DOWNGRADE_RESTORE = 100;
const auto CONTROLLER_DOWNGRADE_SAFEMODE_THRESHOLD = 5000;
const auto CONTROLLER_CLAIM_DOWNGRADE = 300;
const auto CONTROLLER_RESERVE = 1;
const auto CONTROLLER_RESERVE_MAX = 5000;
const auto CONTROLLER_MAX_UPGRADE_PER_TICK = 15;
const auto CONTROLLER_ATTACK_BLOCKED_UPGRADE = 1000;
const auto CONTROLLER_NUKE_BLOCKED_UPGRADE = 200;

const auto SAFE_MODE_DURATION = 20000;
const auto SAFE_MODE_COOLDOWN = 50000;
const auto SAFE_MODE_COST = 1000;

const auto TOWER_HITS = 3000;
const auto TOWER_CAPACITY = 1000;
const auto TOWER_ENERGY_COST = 10;
const auto TOWER_POWER_ATTACK = 600;
const auto TOWER_POWER_HEAL = 400;
const auto TOWER_POWER_REPAIR = 800;
const auto TOWER_OPTIMAL_RANGE = 5;
const auto TOWER_FALLOFF_RANGE = 20;
const auto TOWER_FALLOFF = 0.75;

const auto OBSERVER_HITS = 500;
const auto OBSERVER_RANGE = 10;

const auto POWER_BANK_HITS = 2000000;
const auto POWER_BANK_CAPACITY_MAX = 5000;
const auto POWER_BANK_CAPACITY_MIN = 500;
const auto POWER_BANK_CAPACITY_CRIT = 0.3;
const auto POWER_BANK_DECAY = 5000;
const auto POWER_BANK_HIT_BACK = 0.5;

const auto POWER_SPAWN_HITS = 5000;
const auto POWER_SPAWN_ENERGY_CAPACITY = 5000;
const auto POWER_SPAWN_POWER_CAPACITY = 100;
const auto POWER_SPAWN_ENERGY_RATIO = 50;

const auto EXTRACTOR_HITS = 500;
const auto EXTRACTOR_COOLDOWN = 5;

const auto LAB_HITS = 500;
const auto LAB_MINERAL_CAPACITY = 3000;
const auto LAB_ENERGY_CAPACITY = 2000;
const auto LAB_BOOST_ENERGY = 20;
const auto LAB_BOOST_MINERAL = 30;
const auto LAB_COOLDOWN = 10; // not used
const auto LAB_REACTION_AMOUNT = 5;
const auto LAB_UNBOOST_ENERGY = 0;
const auto LAB_UNBOOST_MINERAL = 15;

const auto GCL_POW = 2.4;
const auto GCL_MULTIPLY = 1000000;
const auto GCL_NOVICE = 3;

// const auto MODE_SIMULATION = null;
// const auto MODE_WORLD = null;

const auto TERRAIN_MASK_WALL = 1;
const auto TERRAIN_MASK_SWAMP = 2;
const auto TERRAIN_MASK_LAVA = 4;

const auto MAX_CONSTRUCTION_SITES = 100;
const auto MAX_CREEP_SIZE = 50;

const auto MINERAL_REGEN_TIME = 50000;
const std::map<std::string, int> MINERAL_MIN_AMOUNT = {{"H", 35000}, {"O", 35000}, {"L", 35000},
                                                       {"K", 35000}, {"Z", 35000}, {"U", 35000},
                                                       {"X", 35000}};
const auto MINERAL_RANDOM_FACTOR = 2;

const std::map<int, int> MINERAL_DENSITY = {{1, 15000}, {2, 35000}, {3, 70000}, {4, 100000}};
const std::map<int, float> MINERAL_DENSITY_PROBABILITY = {{1, 0.1}, {2, 0.5}, {3, 0.9}, {4, 1.0}};
const auto MINERAL_DENSITY_CHANGE = 0.05;

const auto DENSITY_LOW = 1;
const auto DENSITY_MODERATE = 2;
const auto DENSITY_HIGH = 3;
const auto DENSITY_ULTRA = 4;

const auto DEPOSIT_EXHAUST_MULTIPLY = 0.001;
const auto DEPOSIT_EXHAUST_POW = 1.2;
const auto DEPOSIT_DECAY_TIME = 50000;

const auto TERMINAL_CAPACITY = 300000;
const auto TERMINAL_HITS = 3000;
const auto TERMINAL_SEND_COST = 0.1;
const auto TERMINAL_MIN_SEND = 100;
const auto TERMINAL_COOLDOWN = 10;

const auto CONTAINER_HITS = 250000;
const auto CONTAINER_CAPACITY = 2000;
const auto CONTAINER_DECAY = 5000;
const auto CONTAINER_DECAY_TIME = 100;
const auto CONTAINER_DECAY_TIME_OWNED = 500;

const auto NUKER_HITS = 1000;
const auto NUKER_COOLDOWN = 100000;
const auto NUKER_ENERGY_CAPACITY = 300000;
const auto NUKER_GHODIUM_CAPACITY = 5000;
const auto NUKE_LAND_TIME = 50000;
const auto NUKE_RANGE = 10;
const std::map<int, int> NUKE_DAMAGE = {{0, 10000000}, {2, 5000000}};

const auto FACTORY_HITS = 1000;
const auto FACTORY_CAPACITY = 50000;

const auto TOMBSTONE_DECAY_PER_PART = 5;
const auto TOMBSTONE_DECAY_POWER_CREEP = 500;

const auto RUIN_DECAY = 500;
const std::map<std::string, int> RUIN_DECAY_STRUCTURES = {{"powerBank", 10}};

const auto PORTAL_DECAY = 30000;

const auto ORDER_SELL = "sell";
const auto ORDER_BUY = "buy";

const auto MARKET_FEE = 0.05;

const auto MARKET_MAX_ORDERS = 300;
// const std::uint64_t MARKET_ORDER_LIFE_TIME = 1000 * 60 * 60 * 24 * 30;

const auto FLAGS_LIMIT = 10000;

const auto SUBSCRIPTION_TOKEN = "token";
const auto CPU_UNLOCK = "cpuUnlock";
const auto PIXEL = "pixel";
const auto ACCESS_KEY = "accessKey";

const auto PIXEL_CPU_COST = 10000;

const auto RESOURCE_ENERGY = "energy";
const auto RESOURCE_POWER = "power";

const auto RESOURCE_HYDROGEN = "H";
const auto RESOURCE_OXYGEN = "O";
const auto RESOURCE_UTRIUM = "U";
const auto RESOURCE_LEMERGIUM = "L";
const auto RESOURCE_KEANIUM = "K";
const auto RESOURCE_ZYNTHIUM = "Z";
const auto RESOURCE_CATALYST = "X";
const auto RESOURCE_GHODIUM = "G";

const auto RESOURCE_SILICON = "silicon";
const auto RESOURCE_METAL = "metal";
const auto RESOURCE_BIOMASS = "biomass";
const auto RESOURCE_MIST = "mist";

const auto RESOURCE_HYDROXIDE = "OH";
const auto RESOURCE_ZYNTHIUM_KEANITE = "ZK";
const auto RESOURCE_UTRIUM_LEMERGITE = "UL";

const auto RESOURCE_UTRIUM_HYDRIDE = "UH";
const auto RESOURCE_UTRIUM_OXIDE = "UO";
const auto RESOURCE_KEANIUM_HYDRIDE = "KH";
const auto RESOURCE_KEANIUM_OXIDE = "KO";
const auto RESOURCE_LEMERGIUM_HYDRIDE = "LH";
const auto RESOURCE_LEMERGIUM_OXIDE = "LO";
const auto RESOURCE_ZYNTHIUM_HYDRIDE = "ZH";
const auto RESOURCE_ZYNTHIUM_OXIDE = "ZO";
const auto RESOURCE_GHODIUM_HYDRIDE = "GH";
const auto RESOURCE_GHODIUM_OXIDE = "GO";

const auto RESOURCE_UTRIUM_ACID = "UH2O";
const auto RESOURCE_UTRIUM_ALKALIDE = "UHO2";
const auto RESOURCE_KEANIUM_ACID = "KH2O";
const auto RESOURCE_KEANIUM_ALKALIDE = "KHO2";
const auto RESOURCE_LEMERGIUM_ACID = "LH2O";
const auto RESOURCE_LEMERGIUM_ALKALIDE = "LHO2";
const auto RESOURCE_ZYNTHIUM_ACID = "ZH2O";
const auto RESOURCE_ZYNTHIUM_ALKALIDE = "ZHO2";
const auto RESOURCE_GHODIUM_ACID = "GH2O";
const auto RESOURCE_GHODIUM_ALKALIDE = "GHO2";

const auto RESOURCE_CATALYZED_UTRIUM_ACID = "XUH2O";
const auto RESOURCE_CATALYZED_UTRIUM_ALKALIDE = "XUHO2";
const auto RESOURCE_CATALYZED_KEANIUM_ACID = "XKH2O";
const auto RESOURCE_CATALYZED_KEANIUM_ALKALIDE = "XKHO2";
const auto RESOURCE_CATALYZED_LEMERGIUM_ACID = "XLH2O";
const auto RESOURCE_CATALYZED_LEMERGIUM_ALKALIDE = "XLHO2";
const auto RESOURCE_CATALYZED_ZYNTHIUM_ACID = "XZH2O";
const auto RESOURCE_CATALYZED_ZYNTHIUM_ALKALIDE = "XZHO2";
const auto RESOURCE_CATALYZED_GHODIUM_ACID = "XGH2O";
const auto RESOURCE_CATALYZED_GHODIUM_ALKALIDE = "XGHO2";

const auto RESOURCE_OPS = "ops";

const auto RESOURCE_UTRIUM_BAR = "utrium_bar";
const auto RESOURCE_LEMERGIUM_BAR = "lemergium_bar";
const auto RESOURCE_ZYNTHIUM_BAR = "zynthium_bar";
const auto RESOURCE_KEANIUM_BAR = "keanium_bar";
const auto RESOURCE_GHODIUM_MELT = "ghodium_melt";
const auto RESOURCE_OXIDANT = "oxidant";
const auto RESOURCE_REDUCTANT = "reductant";
const auto RESOURCE_PURIFIER = "purifier";
const auto RESOURCE_BATTERY = "battery";

const auto RESOURCE_COMPOSITE = "composite";
const auto RESOURCE_CRYSTAL = "crystal";
const auto RESOURCE_LIQUID = "liquid";

const auto RESOURCE_WIRE = "wire";
const auto RESOURCE_SWITCH = "switch";
const auto RESOURCE_TRANSISTOR = "transistor";
const auto RESOURCE_MICROCHIP = "microchip";
const auto RESOURCE_CIRCUIT = "circuit";
const auto RESOURCE_DEVICE = "device";

const auto RESOURCE_CELL = "cell";
const auto RESOURCE_PHLEGM = "phlegm";
const auto RESOURCE_TISSUE = "tissue";
const auto RESOURCE_MUSCLE = "muscle";
const auto RESOURCE_ORGANOID = "organoid";
const auto RESOURCE_ORGANISM = "organism";

const auto RESOURCE_ALLOY = "alloy";
const auto RESOURCE_TUBE = "tube";
const auto RESOURCE_FIXTURES = "fixtures";
const auto RESOURCE_FRAME = "frame";
const auto RESOURCE_HYDRAULICS = "hydraulics";
const auto RESOURCE_MACHINE = "machine";

const auto RESOURCE_CONDENSATE = "condensate";
const auto RESOURCE_CONCENTRATE = "concentrate";
const auto RESOURCE_EXTRACT = "extract";
const auto RESOURCE_SPIRIT = "spirit";
const auto RESOURCE_EMANATION = "emanation";
const auto RESOURCE_ESSENCE = "essence";

/*
const std::map<int, std::map<int, std::string>> REACTIONS = {
    {H: {O: "OH", L: "LH", K: "KH", U: "UH", Z: "ZH", G, "GH"}},
    {O: {H: "OH", L: "LO", K: "KO", U: "UO", Z: "ZO", G, "GO"}},
    {Z: {K: "ZK", H: "ZH", O, "ZO"}},
    {L: {U: "UL", H: "LH", O, "LO"}},
    {K: {Z: "ZK", H: "KH", O, "KO"}},
    {G: {H: "GH", O, "GO"}},
    {U: {L: "UL", H: "UH", O, "UO"}},
    OH: {
        {UH, "UH2O"},
        {UO, "UHO2"},
        {ZH, "ZH2O"},
        {ZO, "ZHO2"},
        {KH, "KH2O"},
        {KO, "KHO2"},
        {LH, "LH2O"},
        {LO, "LHO2"},
        {GH, "GH2O"},
        GO: "GHO2"
    },
    X: {
        {UH2O, "XUH2O"},
        {UHO2, "XUHO2"},
        {LH2O, "XLH2O"},
        {LHO2, "XLHO2"},
        {KH2O, "XKH2O"},
        {KHO2, "XKHO2"},
        {ZH2O, "XZH2O"},
        {ZHO2, "XZHO2"},
        {GH2O, "XGH2O"},
        GHO2: "XGHO2"
    },
    {ZK: {UL, "G"}},
    {UL: {ZK, "G"}},
    {LH: {OH, "LH2O"}},
    {ZH: {OH, "ZH2O"}},
    {GH: {OH, "GH2O"}},
    {KH: {OH, "KH2O"}},
    {UH: {OH, "UH2O"}},
    {LO: {OH, "LHO2"}},
    {ZO: {OH, "ZHO2"}},
    {KO: {OH, "KHO2"}},
    {UO: {OH, "UHO2"}},
    {GO: {OH, "GHO2"}},
    {LH2O: {X, "XLH2O"}},
    {KH2O: {X, "XKH2O"}},
    {ZH2O: {X, "XZH2O"}},
    {UH2O: {X, "XUH2O"}},
    {GH2O: {X, "XGH2O"}},
    {LHO2: {X, "XLHO2"}},
    {UHO2: {X, "XUHO2"}},
    {KHO2: {X, "XKHO2"}},
    {ZHO2: {X, "XZHO2"}},
    GHO2: {X: "XGHO2"}
};

BOOSTS : {
    work: {
        {UO: {harvest, 3}},
        {UHO2: {harvest, 5}},
        {XUHO2: {harvest, 7}},
        {LH: {build: 1.5, repair, 1.5}},
        {LH2O: {build: 1.8, repair, 1.8}},
        {XLH2O: {build: 2, repair, 2}},
        {ZH: {dismantle, 2}},
        {ZH2O: {dismantle, 3}},
        {XZH2O: {dismantle, 4}},
        {GH: {upgradeController, 1.5}},
        {GH2O: {upgradeController, 1.8}},
        XGH2O: {upgradeController: 2}
    },
    {attack: {UH: {attack: 2}, UH2O: {attack: 3}, XUH2O: {attack, 4}}},
    ranged_attack: {{KO: {rangedAttack: 2, rangedMassAttack, 2}},
                    {KHO2: {rangedAttack: 3, rangedMassAttack, 3}},
                    {XKHO2: {rangedAttack, 4}, rangedMassAttack: 4}},
    heal: {{LO: {heal: 2, rangedHeal, 2}},
           {LHO2: {heal: 3, rangedHeal, 3}},
           {XLHO2: {heal, 4}, rangedHeal: 4}},
    {carry: {KH: {capacity: 2}, KH2O: {capacity: 3}, XKH2O: {capacity, 4}}},
    {move: {ZO: {fatigue: 2}, ZHO2: {fatigue: 3}, XZHO2: {fatigue, 4}}},
    {tough: {GO: {damage: .7}, GHO2: {damage, .5}}, XGHO2: {damage: .3}}
};

REACTION_TIME : {
                    {OH, 20},     {ZK, 5},  {UL, 5},    {G, 5},       {UH, 10}, {UH2O, 5},
                    {XUH2O, 60},  {UO, 10}, {UHO2, 5},  {XUHO2, 60},  {KH, 10}, {KH2O, 5},
                    {XKH2O, 60},  {KO, 10}, {KHO2, 5},  {XKHO2, 60},  {LH, 15}, {LH2O, 10},
                    {XLH2O, 65},  {LO, 10}, {LHO2, 5},  {XLHO2, 60},  {ZH, 20}, {ZH2O, 40},
                    {XZH2O, 160}, {ZO, 10}, {ZHO2, 5},  {XZHO2, 60},  {GH, 10}, {GH2O, 15},
                    {XGH2O, 80},  {GO, 10}, {GHO2, 30}, {XGHO2, 150},
                };
*/

const auto PORTAL_UNSTABLE = 10 * 24 * 3600 * 1000;
const auto PORTAL_MIN_TIMEOUT = 12 * 24 * 3600 * 1000;
const auto PORTAL_MAX_TIMEOUT = 22 * 24 * 3600 * 1000;

const auto POWER_BANK_RESPAWN_TIME = 50000;

const auto INVADERS_ENERGY_GOAL = 100000;

const auto SYSTEM_USERNAME = "Screeps";

// SIGN_NOVICE_AREA and SIGN_RESPAWN_AREA constants are deprecated, please use SIGN_PLANNED_AREA instead
const auto SIGN_NOVICE_AREA =
    "A new Novice or Respawn Area is being planned somewhere in this sector. Please make sure all "
    "important rooms are reserved.";
const auto SIGN_RESPAWN_AREA =
    "A new Novice or Respawn Area is being planned somewhere in this sector. Please make sure all "
    "important rooms are reserved.";
const auto SIGN_PLANNED_AREA =
    "A new Novice or Respawn Area is being planned somewhere in this sector. Please make sure all "
    "important rooms are reserved.";

const auto EVENT_ATTACK = 1;
const auto EVENT_OBJECT_DESTROYED = 2;
const auto EVENT_ATTACK_CONTROLLER = 3;
const auto EVENT_BUILD = 4;
const auto EVENT_HARVEST = 5;
const auto EVENT_HEAL = 6;
const auto EVENT_REPAIR = 7;
const auto EVENT_RESERVE_CONTROLLER = 8;
const auto EVENT_UPGRADE_CONTROLLER = 9;
const auto EVENT_EXIT = 10;
const auto EVENT_POWER = 11;
const auto EVENT_TRANSFER = 12;

const auto EVENT_ATTACK_TYPE_MELEE = 1;
const auto EVENT_ATTACK_TYPE_RANGED = 2;
const auto EVENT_ATTACK_TYPE_RANGED_MASS = 3;
const auto EVENT_ATTACK_TYPE_DISMANTLE = 4;
const auto EVENT_ATTACK_TYPE_HIT_BACK = 5;
const auto EVENT_ATTACK_TYPE_NUKE = 6;

const auto EVENT_HEAL_TYPE_MELEE = 1;
const auto EVENT_HEAL_TYPE_RANGED = 2;

const auto POWER_LEVEL_MULTIPLY = 1000;
const auto POWER_LEVEL_POW = 2;
const auto POWER_CREEP_SPAWN_COOLDOWN = 8 * 3600 * 1000;
const auto POWER_CREEP_DELETE_COOLDOWN = 24 * 3600 * 1000;
const auto POWER_CREEP_MAX_LEVEL = 25;
const auto POWER_CREEP_LIFE_TIME = 5000;

// const POWER_CLASS = {OPERATOR: "operator"};

const auto PWR_GENERATE_OPS = 1;
const auto PWR_OPERATE_SPAWN = 2;
const auto PWR_OPERATE_TOWER = 3;
const auto PWR_OPERATE_STORAGE = 4;
const auto PWR_OPERATE_LAB = 5;
const auto PWR_OPERATE_EXTENSION = 6;
const auto PWR_OPERATE_OBSERVER = 7;
const auto PWR_OPERATE_TERMINAL = 8;
const auto PWR_DISRUPT_SPAWN = 9;
const auto PWR_DISRUPT_TOWER = 10;
const auto PWR_DISRUPT_SOURCE = 11;
const auto PWR_SHIELD = 12;
const auto PWR_REGEN_SOURCE = 13;
const auto PWR_REGEN_MINERAL = 14;
const auto PWR_DISRUPT_TERMINAL = 15;
const auto PWR_OPERATE_POWER = 16;
const auto PWR_FORTIFY = 17;
const auto PWR_OPERATE_CONTROLLER = 18;
const auto PWR_OPERATE_FACTORY = 19;

const auto EFFECT_INVULNERABILITY = 1001;
const auto EFFECT_COLLAPSE_TIMER = 1002;

const auto INVADER_CORE_HITS = 100000;
const std::map<int, int> INVADER_CORE_CREEP_SPAWN_TIME = {{0, 0}, {1, 0}, {2, 6},
                                                          {3, 3}, {4, 2}, {5, 1}};
const std::map<int, int> INVADER_CORE_EXPAND_TIME = {{1, 4000},
                                                     {2, 3500},
                                                     {3, 3000},
                                                     {4, 2500},
                                                     {5, 2000}};

const auto INVADER_CORE_CONTROLLER_POWER = 2;
const auto INVADER_CORE_CONTROLLER_DOWNGRADE = 5000;
const std::map<int, int> STRONGHOLD_RAMPART_HITS = {{0, 0},      {1, 100000},  {2, 200000},
                                                    {3, 500000}, {4, 1000000}, {5, 2000000}};
const auto STRONGHOLD_DECAY_TICKS = 75000;

} // namespace Screeps

#endif // SCREEPS_CONSTANTS_HPP
