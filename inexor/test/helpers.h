#ifndef INEXOR_TEST_HELPERS_HEADER
#define INEXOR_TEST_HELPERS_HEADER

#include "gtest/gtest.h"

#include <random>

#define test TEST

#undef assert // Ignore assert.h asserts
#define assert ASSERT_TRUE
#define assertThrow ASSERT_THROW
#define assertEq ASSERT_EQ
#define assertNeq ASSERT_NE

#define expect EXPECT_TRUE
#define expectThrow EXPECT_THROW
#define expectEq EXPECT_EQ
#define expectNeq EXPECT_NE

// TODO: Seed?
extern std::default_random_engine trand;

/// Copy any number of random bytes into a buffer
///
/// @param dst – The buffer to write to
/// @param len – The size of the buffer
void rndcopy(void *dst, size_t len);

/// Create a random number
///
/// @tparam R The type of the random number
/// @param a The minimum value of the number, by default the
///          minimum number the type supports
/// @param z The maximum value of the number, by default the
///          maximum value the type supports
/// @return A random number of type R between [a; z]
template <typename R=int>
R rand(R a=std::numeric_limits<R>::min(),
       R z=std::numeric_limits<R>::max()) {
  std::uniform_int_distribution<R> d(a,z);
  return d(trand);
}

#endif
