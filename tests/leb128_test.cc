/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems Inc
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the “Software”), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#include "leb128.h"
#include "gtest/gtest.h"

/* Test minimum input */
TEST(Leb128, MinInput) {
  uint8_t buf[10];
  int64_t input = std::numeric_limits<int64_t>::min();
  int64_t output = 0;
  std::size_t bytes_written = bfs::EncodeLeb128(input, buf, sizeof(buf));
  std::size_t bytes_read = bfs::DecodeLeb128(buf, sizeof(buf), &output);
  EXPECT_EQ(10, bytes_written);
  EXPECT_EQ(10, bytes_read);
  EXPECT_EQ(std::numeric_limits<int64_t>::min(), output);
}
/* Test maximum input */
TEST(Leb128, MaxInput) {
  uint8_t buf[10];
  int64_t input = std::numeric_limits<int64_t>::max();
  int64_t output = 0;
  std::size_t bytes_written = bfs::EncodeLeb128(input, buf, sizeof(buf));
  std::size_t bytes_read = bfs::DecodeLeb128(buf, sizeof(buf), &output);
  EXPECT_EQ(10, bytes_written);
  EXPECT_EQ(10, bytes_read);
  EXPECT_EQ(std::numeric_limits<int64_t>::max(), output);
}
/* Test mid input */
TEST(Leb128, MidInput) {
  uint8_t buf[10];
  int64_t input = -12345;
  int64_t output = 0;
  std::size_t bytes_written = bfs::EncodeLeb128(input, buf, sizeof(buf));
  std::size_t bytes_read = bfs::DecodeLeb128(buf, sizeof(buf), &output);
  EXPECT_EQ(3, bytes_written);
  EXPECT_EQ(3, bytes_read);
  EXPECT_EQ(-12345, output);
}
/* Test small write buffer */
TEST(Leb128, WriteBuffer) {
  uint8_t buf[1];
  int64_t input = 12345;
  std::size_t bytes_written = bfs::EncodeLeb128(input, buf, sizeof(buf));
  EXPECT_EQ(0, bytes_written);
}
/* Test small read buffer */
TEST(Leb128, ReadBuffer) {
  uint8_t buf[10];
  int64_t input = 12345;
  int64_t output = 0;
  std::size_t bytes_written = bfs::EncodeLeb128(input, buf, sizeof(buf));
  std::size_t bytes_read = bfs::DecodeLeb128(buf, 1, &output);
  EXPECT_EQ(0, bytes_read);
}
/* Test null pointer */
TEST(Leb128, NullPointer) {
  uint8_t buf[10];
  int64_t input = 12345;
  int64_t output = 0;
  std::size_t bytes_written = bfs::EncodeLeb128(input, buf, sizeof(buf));
  std::size_t bytes_read = bfs::DecodeLeb128(buf, 1, NULL);
  EXPECT_EQ(0, bytes_read);
}
