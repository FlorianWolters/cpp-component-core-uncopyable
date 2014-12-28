# fw::core::UncopyableMixin

The uncopyable (a. k. a. non-copyable) Mixin idiom as a C++11 component.

[![Build Status](https://travis-ci.org/FlorianWolters/cpp-component-core-uncopyable-mixin.svg)](https://travis-ci.org/FlorianWolters/cpp-component-core-uncopyable-mixin)

## Table of Contents (ToC)

* [Introduction](#introduction)
* [Features](#features)
* [Requirements](#requirements)
* [Usage](#usage)
* [Installation](#installation)
* [Testing](#testing)
* [Contributing](#contributing)
* [Credits](#credits)
* [License](#license)

## Introduction

**fw::core::UncopyableMixin** is an adoption of *Item 6: Explicitly disallow the
use of compiler-generated functions you do not want* from the book [Effective
C++: 55 Specific Ways to Improve Your Programs and Designs][50] by
Scott Meyers.

The implementation uses the following idioms:

* [Non-copyable Mixin][19]
* [Curiously Recurring Template Pattern (CRTP)][20]

## Features

**fw::core::UncopyableMixin** is a modern version of [boost::noncopyable][51]:

* Allows for *Empty Base Optimization* with multiple inheritance.
* Clean code, e. g. no usage of preprocessor macros.
* Natural name which cleanly indicates its purpose:

  > "It's a fine class, I just find the name a bit un-, er, *non*natural."

  -- S. Meyer: Effective C++. Boston: Pearson Education, 2008, p. 39

## Requirements

### Production

* [CMake][1]
* [GNU Compiler Collection (GCC)][2] >= 4.6

### Development

* [Google Test][3]

## Installation

WIP: Biicode integration is coming!

## Usage

    #include "fw/core/uncopyable_mixin.h"

    class MyUncopyable final : private fw::core::UncopyableMixin<MyUncopyable> {
    };

## Testing

    mkdir build && cmake .. && make && ctest

## Contributing

Please see [CONTRIBUTING](CONTRIBUTING.md) for details.

## Credits

* [Florian Wolters][100]
* [All Contributors][101]

## License

Copyright Florian Wolters 2014 (http://blog.florianwolters.de).

Distributed under the Boost Software License, Version 1.0. (See accompanying
file [LICENSE_1_0.txt](LICENSE_1_0.txt) or copy at
<http://www.boost.org/LICENSE_1_0.txt>)

[1]: http://cmake.org
     "CMake"
[2]: https://gcc.gnu.org
     "GCC, the GNU Compiler Collection"
[3]: https://code.google.com/p/googletest
     "Google Test"
[19]: https://en.wikibooks.org/wiki/More_C++_Idioms/Non-copyable_Mixin
[20]: https://en.wikibooks.org/wiki/More_C++_Idioms/Curiously_Recurring_Template_Pattern
[50]: https://books.google.de/books?id=Qx5oyB49poYC
[51]: http://boost.org/libs/core/noncopyable.htm
      "noncopyable"
[100]: https://github.com/FlorianWolters
       "FlorianWolters · GitHub"
[101]: https://github.com/FlorianWolters/cpp-component-core-uncopyable-mixin/contributors
       "Contributors to FlorianWolters/cpp-component-core-uncopyable-mixin"
