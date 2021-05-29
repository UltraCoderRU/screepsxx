#ifndef SCREEPS_MACRO_HPP
#define SCREEPS_MACRO_HPP

#include <cassert>

#define SCREEPS_ASSERT(expr) assert(expr)
#define SCREEPS_ASSERT_MSG(expr, msg) assert(expr&& msg)
#define SCREEPS_ASSERT_FALSE(msg) SCREEPS_ASSERT_MSG(false, msg)
#define SCREEPS_PRECONDITION(expr) SCREEPS_ASSERT_MSG(expr, "precondition failed")
#define SCREEPS_POSTCONDITION(expr) SCREEPS_ASSERT_MSG(expr, "postcondition failed")

#endif // SCREEPS_MACRO_HPP
