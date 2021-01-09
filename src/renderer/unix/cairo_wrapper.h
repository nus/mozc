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

#ifndef MOZC_RENDERER_UNIX_CAIRO_WRAPPER_H_
#define MOZC_RENDERER_UNIX_CAIRO_WRAPPER_H_

#include <gtk/gtk.h>

#include "base/port.h"
#include "renderer/unix/cairo_wrapper_interface.h"

namespace mozc {
namespace renderer {
namespace gtk {

class CairoWrapper : public CairoWrapperInterface {
 public:
  explicit CairoWrapper(GdkWindow *window);
  virtual ~CairoWrapper();

  virtual void Save();
  virtual void Restore();
  virtual void SetSourceRGBA(double r, double g, double b, double a);
  virtual void Rectangle(double x, double y, double width, double height);
  virtual void Fill();
  virtual void SetLineWidth(double width);
  virtual void Stroke();
  virtual void MoveTo(double x, double y);
  virtual void LineTo(double x, double y);

 private:
  cairo_t *cairo_context_;
  DISALLOW_COPY_AND_ASSIGN(CairoWrapper);
};

}  // namespace gtk
}  // namespace renderer
}  // namespace mozc

#endif  // MOZC_RENDERER_UNIX_CAIRO_WRAPPER_H_
