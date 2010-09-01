/*
 * Copyright 2010, The Android Open Source Project
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ChromiumIncludes_h
#define ChromiumIncludes_h

// Include all external/chromium files in this file so the problems with the LOG
// and LOG_ASSERT defines can be handled in one place.

// Undefine LOG and LOG_ASSERT before including chrome code, and if they were
// defined attempt to set the macros to the Android logging macros (which are
// the only ones that actually log).

#ifdef LOG
#define LOG_WAS_DEFINED LOG
#undef LOG
#endif

#ifdef LOG_ASSERT
#define LOG_ASSERT_WAS_DEFINED LOG_ASSERT
#undef LOG_ASSERT
#endif

#include <base/condition_variable.h>
#include <base/lock.h>
#include <base/message_loop_proxy.h>
#include <base/ref_counted.h>
#include <base/string_util.h>
#include <base/thread.h>
#include <base/tuple.h>
#include <chrome/browser/net/sqlite_persistent_cookie_store.h>
#include <net/base/cookie_monster.h>
#include <net/base/data_url.h>
#include <net/base/io_buffer.h>
#include <net/base/ssl_config_service.h>
#include <net/http/http_auth_handler_factory.h>
#include <net/http/http_cache.h>
#include <net/http/http_network_layer.h>
#include <net/http/http_response_headers.h>
#include <net/proxy/proxy_service.h>
#include <net/url_request/url_request.h>
#include <net/url_request/url_request_context.h>

#undef LOG
#if defined(LOG_WAS_DEFINED) && defined(LOG_PRI)
#define LOG(priority, tag, ...) LOG_PRI(ANDROID_##priority, tag, __VA_ARGS__)
#endif

#undef LOG_ASSERT
#if defined(LOG_ASSERT_WAS_DEFINED) && defined(LOG_FATAL_IF)
#define LOG_ASSERT(cond, ...) LOG_FATAL_IF(!(cond), ## __VA_ARGS__)
#endif

#endif
