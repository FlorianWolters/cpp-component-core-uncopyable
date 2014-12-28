/**
 * Declares the `fw::core::UncopyableMixin` class.
 *
 * @file fw/core/uncopyable_mixin.h
 * @author Florian Wolters <wolters.fl@gmail.com>
 *
 * @section License
 *
 * Copyright Florian Wolters 2014 (http://blog.florianwolters.de).
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef FW_CORE_UNCOPYABLE_MIXIN_H_
#define FW_CORE_UNCOPYABLE_MIXIN_H_

namespace fw {
namespace core {

/**
 * The `UncopyableMixin` class prevents objects of a class from being
 * copy-constructed or assigned to each other.
 *
 * `UncopyableMixin` instances should **not** be constructed in standard
 * programming.
 *
 * Instead, the class should be used as:
 *
 *     #include "fw/core/uncopyable_mixin.h"
 *
 *     class MyUncopyable final
 *         : private fw::core::UncopyableMixin<MyUncopyable> {
 *     };
 *
 * `UncopyableMixin` implements the *Curiously Recurring Template Pattern
 * (CRTP)* (a. k. a. Mixin-from-above) idiom.
 *
 * @author Florian Wolters <wolters.fl@gmail.com>
 * @tparam TDerived The type of the derived class.
 */
template <class TDerived>
class UncopyableMixin {
 public:
  /**
   * Deleted copy constructor.
   */
  UncopyableMixin(UncopyableMixin const&) = delete;

  /**
   * Deleted assignment operator.
   *
   * @return n/a
   */
  UncopyableMixin& operator=(UncopyableMixin const&) = delete;

 protected:
  /**
   * Initializes a new instance of the `UncopyableMixin` class.
   */
  UncopyableMixin() = default;

  /**
   * Finalizes an instance of the `UncopyableMixin` class.
   */
  ~UncopyableMixin() = default;
};

}  // namespace core
}  // namespace fw

#endif  // FW_CORE_UNCOPYABLE_MIXIN_H_
