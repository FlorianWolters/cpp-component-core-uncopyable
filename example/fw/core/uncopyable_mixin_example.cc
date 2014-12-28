/**
 * Provides usage examples for the `fw::core::UncopyableMixin` class.
 *
 * @file fw/core/uncopyable_mixin_example.cc
 * @author Florian Wolters <wolters.fl@gmail.com>
 *
 * @section License
 *
 * Copyright Florian Wolters 2014 (http://blog.florianwolters.de).
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <cassert> 
#include <iostream> 
#include <type_traits> 

#include "fw/core/uncopyable_mixin.h"

class MyUncopyable final : private fw::core::UncopyableMixin<MyUncopyable> {
 public:
  int value;
};

int main() {
  std::cout << std::boolalpha; 
  std::cout << "is_constructible: " << std::is_constructible<MyUncopyable>::value << '\n';
  std::cout << "is_default_constructible: " << std::is_default_constructible<MyUncopyable>::value << '\n';
  std::cout << "has_trivial_copy_constructor: " << std::has_trivial_copy_constructor<MyUncopyable>::value << '\n';

/* TODO(wolters): Write automated unit test if type traits are fully implemented.
  std::cout << "is_trivially_copyable: " << std::is_trivially_copyable<MyUncopyable>::value << '\n';
  std::cout << "is_trivially_constructible: " << std::is_trivially_constructible<MyUncopyable>::value << '\n';
  std::cout << "is_trivially_default_constructible: " << std::is_trivially_default_constructible<MyUncopyable>::value << '\n';
  std::cout << "is_trivially_copy_constructible: " << std::is_trivially_copy_constructible<MyUncopyable>::value << '\n';
  std::cout << "is_trivially_move_constructible: " << std::is_trivially_move_constructible<MyUncopyable>::value << '\n';
  std::cout << "is_trivially_assignable: " << std::is_trivially_assignable<MyUncopyable>::value << '\n';
  std::cout << "is_trivially_default_assignable: " << std::is_trivially_default_assignable<MyUncopyable>::value << '\n';
  std::cout << "is_trivially_copy_assignable: " << std::is_trivially_copy_assignable<MyUncopyable>::value << '\n';
  std::cout << "is_trivially_move_assignable: " << std::is_trivially_move_assignable<MyUncopyable>::value << '\n';
*/
  MyUncopyable my_uncopyable;
  MyUncopyable my_second_uncopyable;
  //MyUncopyable my_uncopyable_copy{my_uncopyable};
  //my_uncopyable = my_second_uncopyable;
}
