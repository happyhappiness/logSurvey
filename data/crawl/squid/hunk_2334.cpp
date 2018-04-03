-/*
- * $Id$
- *
- * DEBUG: section 84    Helper process maintenance
- * AUTHOR: Robert Collins
- *
- * SQUID Web Proxy Cache          http://www.squid-cache.org/
- * ----------------------------------------------------------
- *
- *  Squid is the result of efforts by numerous individuals from
- *  the Internet community; see the CONTRIBUTORS file for full
- *  details.   Many organizations have provided support for Squid's
- *  development; see the SPONSORS file for full details.  Squid is
- *  Copyrighted (C) 2001 by the Regents of the University of
- *  California; see the COPYRIGHT file for full details.  Squid
- *  incorporates software developed and/or copyrighted by other
- *  sources; see the CREDITS file for full details.
- *
- *  This program is free software; you can redistribute it and/or modify
- *  it under the terms of the GNU General Public License as published by
- *  the Free Software Foundation; either version 2 of the License, or
- *  (at your option) any later version.
- *
- *  This program is distributed in the hope that it will be useful,
- *  but WITHOUT ANY WARRANTY; without even the implied warranty of
- *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
- *  GNU General Public License for more details.
- *
- *  You should have received a copy of the GNU General Public License
- *  along with this program; if not, write to the Free Software
- *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
- *
- */
-
-#include "squid.h"
+#include "config.h"
 #include "HttpReply.h"
 
-HttpReply::HttpReply() : HttpMsg(hoReply)
-{
-    fatal ("Not implemented.");
-}
-
-HttpReply::~HttpReply()
-{
-    fatal ("Not implemented.");
-}
-
-void
-HttpReply::setHeaders(http_status status, const char *reason,
-                      const char *ctype, int64_t clen, time_t lmt, time_t expires_)
-{
-    fatal ("Not implemented");
-}
+#define STUB_API "HttpReply.cc"
+#include "tests/STUB.h"
 
-void
-HttpReply::packHeadersInto(Packer * p) const
-{
-    fatal ("Not implemented");
-}
-
-void HttpReply::reset()
-{
-    fatal ("Not implemented");
-}
-
-void
-httpBodyPackInto(const HttpBody * body, Packer * p)
-{
-    fatal ("Not implemented");
-}
-
-bool
-HttpReply::sanityCheckStartLine(MemBuf *buf, const size_t hdr_len, http_status *error)
-{
-    fatal ("Not implemented");
-    return false;
-}
-
-int
-HttpReply::httpMsgParseError()
-{
-    fatal ("Not implemented");
-    return 0;
-}
-
-bool
-HttpReply::expectingBody(const HttpRequestMethod&, int64_t&) const
-{
-    fatal ("Not implemented");
-    return false;
-}
-
-void
-HttpReply::packFirstLineInto(Packer * p, bool) const
-{
-    fatal ("Not implemented");
-}
-
-bool
-HttpReply::parseFirstLine(const char *start, const char *end)
-{
-    fatal ("Not implemented");
-    return false;
-}
-
-void
-HttpReply::hdrCacheInit()
-{
-    fatal ("Not implemented");
-}
-
-HttpReply *
-HttpReply::clone() const
-{
-    fatal("Not implemented");
-    return NULL;
-}
-
-bool
-HttpReply::inheritProperties(const HttpMsg *aMsg)
-{
-    fatal("Not implemented");
-    return false;
-}
-
-int64_t
-HttpReply::bodySize(const HttpRequestMethod&) const
+HttpReply::HttpReply() : HttpMsg(hoReply)
 {
-    fatal("Not implemented");
-    return 0;
-}
+// XXX: required by testStore
+// STUB
+}
+HttpReply::~HttpReply() STUB
+void HttpReply::setHeaders(http_status status, const char *reason, const char *ctype, int64_t clen, time_t lmt, time_t expires_) STUB
+void HttpReply::packHeadersInto(Packer * p) const STUB
+void HttpReply::reset() STUB
+void httpBodyPackInto(const HttpBody * body, Packer * p) STUB
+bool HttpReply::sanityCheckStartLine(MemBuf *buf, const size_t hdr_len, http_status *error) STUB_RETVAL(false)
+int HttpReply::httpMsgParseError() STUB_RETVAL(0)
+bool HttpReply::expectingBody(const HttpRequestMethod&, int64_t&) const STUB_RETVAL(false)
+void HttpReply::packFirstLineInto(Packer * p, bool) const STUB
+bool HttpReply::parseFirstLine(const char *start, const char *end) STUB_RETVAL(false)
+void HttpReply::hdrCacheInit() STUB
+HttpReply * HttpReply::clone() const STUB_RETVAL(NULL)
+bool HttpReply::inheritProperties(const HttpMsg *aMsg) STUB_RETVAL(false)
+int64_t HttpReply::bodySize(const HttpRequestMethod&) const STUB_RETVAL(0)
