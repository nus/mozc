// Copyright 2010-2021, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef MOZC_BASE_MMAP_H_
#define MOZC_BASE_MMAP_H_

#include <cstddef>

#include "absl/strings/string_view.h"
#include "absl/types/span.h"

namespace mozc {

class Mmap final {
 public:
  Mmap() = default;

  Mmap(const Mmap &) = delete;
  Mmap &operator=(const Mmap &) = delete;

  ~Mmap() { Close(); }

  bool Open(absl::string_view filename, absl::string_view mode = "r");
  void Close();

  // Following mlock/munlock related functions work based on target environment.
  // In Android, Native Client, and Windows, we don't implement mlock, so these
  // functions returns false and -1. For other target platforms, these functions
  // call actual mlock/munlock functions and return it's result.
  // On Android, page-out is probably acceptable because
  // - Smaller RAM on the device.
  // - The storage is (usually) solid state thus page-in/out is expected to
  //   be faster.
  // On Linux, in the kernel version >= 2.6.9, user process can mlock. In older
  // kernel, it fails if the process is running in user privilege.
  // TODO(team): Check if mlock is really necessary for Mac.
  static bool IsMLockSupported();
  static int MaybeMLock(const void *addr, size_t len);
  static int MaybeMUnlock(const void *addr, size_t len);

  constexpr char &operator[](size_t i) { return data_[i]; }
  constexpr char operator[](size_t i) const { return data_[i]; }
  constexpr char *begin() { return data_.begin(); }
  constexpr const char *begin() const { return data_.begin(); }
  constexpr char *end() { return data_.end(); }
  constexpr const char *end() const { return data_.end(); }
  constexpr char *data() { return data_.data(); }
  constexpr const char *data() const { return data_.data(); }
  constexpr absl::Span<char> span() { return data_; }
  constexpr absl::Span<const char> span() const { return data_; }

  constexpr size_t size() const { return data_.size(); }

 private:
  absl::Span<char> data_;
};

}  // namespace mozc

#endif  // MOZC_BASE_MMAP_H_
