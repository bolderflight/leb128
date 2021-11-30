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
#include <limits>

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  uint8_t buf[100];
  int64_t read_val = 0;
  /* Try encoding and decoding the maximum int64 value */
  int64_t orig_val = std::numeric_limits<int64_t>::max();
  Serial.print("Written value: ");
  Serial.println(orig_val);
  Serial.print("Bytes written: ");
  Serial.println(bfs::EncodeLeb128(orig_val, buf, sizeof(buf)));
  Serial.print("Bytes read: ");
  Serial.println(bfs::DecodeLeb128(buf, sizeof(buf), &read_val));
  Serial.print("Read value: ");
  Serial.println(read_val);
  /* Try encoding and decoding the minimum int64 value */
  orig_val = std::numeric_limits<int64_t>::min();
  Serial.print("Written value: ");
  Serial.println(orig_val);
  Serial.print("Bytes written: ");
  Serial.println(bfs::EncodeLeb128(orig_val, buf, sizeof(buf)));
  Serial.print("Bytes read: ");
  Serial.println(bfs::DecodeLeb128(buf, sizeof(buf), &read_val));
  Serial.print("Read value: ");
  Serial.println(read_val);
  /* Try encoding and decoding some random value */
  orig_val = -12345;
  Serial.print("Written value: ");
  Serial.println(orig_val);
  Serial.print("Bytes written: ");
  Serial.println(bfs::EncodeLeb128(orig_val, buf, sizeof(buf)));
  Serial.print("Bytes read: ");
  Serial.println(bfs::DecodeLeb128(buf, sizeof(buf), &read_val));
  Serial.print("Read value: ");
  Serial.println(read_val);
}

void loop() {}
