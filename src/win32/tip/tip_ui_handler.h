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

#ifndef MOZC_WIN32_TIP_TIP_UI_HANDLER_H_
#define MOZC_WIN32_TIP_TIP_UI_HANDLER_H_

#include <windows.h>
#include <msctf.h>

#include "base/port.h"

namespace mozc {
namespace win32 {
namespace tsf {

class TipTextService;

class TipUiHandler {
 public:
  enum UiType {
    kSuggestWindow,
    kCandidateWindow,
    kIndicatorWindow,
  };

  TipUiHandler() = delete;
  TipUiHandler(const TipUiHandler &) = delete;
  TipUiHandler &operator=(const TipUiHandler &) = delete;

  static ITfUIElement *CreateUI(UiType type, TipTextService *text_service,
                                ITfContext *context);
  static void OnDestroyElement(TipTextService *text_service,
                               ITfUIElement *element);

  static void OnActivate(TipTextService *text_service);
  static void OnDeactivate(TipTextService *text_service);
  static void OnDocumentMgrChanged(TipTextService *text_service,
                                   ITfDocumentMgr *document_manager);
  static void OnFocusChange(TipTextService *text_service,
                            ITfDocumentMgr *focused_document_manager);
  static bool Update(TipTextService *text_service, ITfContext *context,
                     TfEditCookie readable_cookie);
  static bool OnDllProcessAttach(HINSTANCE module_handle, bool static_loading);
  static void OnDllProcessDetach(HINSTANCE module_handle,
                                 bool process_shutdown);
};

}  // namespace tsf
}  // namespace win32
}  // namespace mozc

#endif  // MOZC_WIN32_TIP_TIP_UI_HANDLER_H_
