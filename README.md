[![Pipeline](https://gitlab.com/bolderflight/software/leb128/badges/main/pipeline.svg)](https://gitlab.com/bolderflight/software/leb128/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

![Bolder Flight Systems Logo](img/logo-words_75.png) &nbsp; &nbsp; ![Arduino Logo](img/arduino_logo_75.png)

# Leb128
Signed little endian base 128 (LEB128) implementation, which stores arbitrarily large signed integers in a variable length format. This library is compatible with Arduino ARM and with CMake build systems. It would also be easy to include with other projects, since it is a header only library consisting of a single file.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

# Installation

## Arduino
Use the Arduino Library Manager to install this library or clone to your Arduino/libraries folder. This library is added as:

```C++
#include "leb128.h"
```

An example Arduino executable is located at *examples/arduino/leb128_example/leb128_example.ino*. Teensy 3.x, 4.x, and LC devices are used for testing under Arduino and this library should be compatible with other ARM devices. This library is *not* expected to work on AVR devices.

## CMake
CMake is used to build this library, which is exported as a library target called *leb128*. The header is added as:

```C++
#include "leb128.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library, an example executable called *leb128_example*, and an executable for testing using the Google Test framework, called *leb128_test*. The example executable source file is located at *examples/cmake/leb128_example.cc*.

# Namespace
This library is within the namespace *bfs*.

# Functions

**std::size_t EncodeLeb128(int64_t val, uint8_t &ast; const data, const std::size_t len)** Encodes an int64_t *val* into a LEB128 variable length format stored in the array *data* of length *len*. Returns the number of bytes written if successful, otherwise, returns 0.

**std::size_t DecodeLeb128(uint8_t const &ast; const data, const std::size_t len, int64_t &ast; const val)** Decodes a LEB128 variable length value from the array *data* of length *len* into an int64_t variable *val*. Returns the number of bytes read if successful, otherwise, returns 0.

```C++
uint8_t buf[100];
int64_t read_val = 0;
int64_t orig_val = std::numeric_limits<int64_t>::max();
std::size_t bytes_written = bfs::EncodeLeb128(orig_val, buf, sizeof(buf));
std::size_t bytes_read = bfs::DecodeLeb128(buf, sizeof(buf), &read_val);
```
