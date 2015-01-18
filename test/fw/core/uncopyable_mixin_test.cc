/**
 * Contains test cases for the `fw::core::UncopyableMixin` class.
 *
 * @file    fw/core/uncopyable_mixin_test.cc
 * @author  Florian Wolters <wolters.fl@gmail.com>
 * @section License
 *
 * Copyright Florian Wolters 2014 (http://blog.florianwolters.de).
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <type_traits>

#include "gtest/gtest.h"

#include "fw/core/uncopyable_mixin.h"

namespace fw {
namespace core {
namespace testing {

class UncopyableExampleImpl final
    : private fw::core::UncopyableMixin<UncopyableExampleImpl> {
 public:
  /**
   * Initializes a new instance of the UncopyableExampleImpl class with the
   * specified value.
   *
   * @param kValue The value.
   */
  explicit UncopyableExampleImpl(int const kValue) : value_(kValue) {
    // NOOP
  }

 private:
  int value_;
};

TEST(UncopyableMixinTest, IsConstructible) {
  ASSERT_FALSE(std::is_constructible<UncopyableExampleImpl>::value);
}

TEST(UncopyableMixinTest, HasTrivialCopyConstructor) {
  ASSERT_TRUE(std::has_trivial_copy_constructor<UncopyableExampleImpl>::value);
}

}  // namespace testing
}  // namespace core
}  // namespace fw

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
