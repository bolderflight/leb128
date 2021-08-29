# Leb128
Signed little endian base 128 (LEB128) implementation, which stores arbitrarily large signed integers in a variable length format.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

## Installation
CMake is used to build this library, which is exported as a library target called *leb128*. The header is added as:

```
#include "leb128/leb128.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library, an example executable called *leb128_example*, and an executable for testing using the Google Test framework, called *leb128_test*. The example executable source file is located at *examples/leb128_example.cc*.

## Namespace
This library is within the namespace *bfs*.

## Functions

**std::size_t EncodeLeb128(int64_t val, std::span<uint8_t> data)** Encodes an int64_t *val* into a LEB128 variable length format stored in the array viewed by the span *data*. Returns the number of bytes written if successful, otherwise, returns 0.

**std::size_t DecodeLeb128(std::span<uint8_t> data, int64_t &ast; const val)** Decodes a LEB128 variable length value from the array viewed by the span *data* into an int64_t variable *val*. Returns the number of bytes read if successful, otherwise, returns 0.

```C++
uint8_t buf[100];
int64_t read_val = 0;
int64_t orig_val = std::numeric_limits<int64_t>::max();
std::size_t bytes_written = bfs::EncodeLeb128(orig_val, buf);
std::size_t bytes_read = bfs::DecodeLeb128(buf, &read_val);
```
