  * Encodes abstract data types into a machine independent stream of bytes.
  *
  */
-/**********************************************************************
-	Copyright 1988, 1989, 1991, 1992 by Carnegie Mellon University
-
-                      All Rights Reserved
-
-Permission to use, copy, modify, and distribute this software and its 
-documentation for any purpose and without fee is hereby granted, 
-provided that the above copyright notice appear in all copies and that
-both that copyright notice and this permission notice appear in 
-supporting documentation, and that the name of CMU not be
-used in advertising or publicity pertaining to distribution of the
-software without specific, written prior permission.  
-
-CMU DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
-ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
-CMU BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
-ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
-WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
-ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
-SOFTWARE.
-******************************************************************/
+/***************************************************************************
+ *
+ *           Copyright 1997 by Carnegie Mellon University
+ * 
+ *                       All Rights Reserved
+ * 
+ * Permission to use, copy, modify, and distribute this software and its
+ * documentation for any purpose and without fee is hereby granted,
+ * provided that the above copyright notice appear in all copies and that
+ * both that copyright notice and this permission notice appear in
+ * supporting documentation, and that the name of CMU not be
+ * used in advertising or publicity pertaining to distribution of the
+ * software without specific, written prior permission.
+ * 
+ * CMU DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
+ * ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
+ * CMU BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
+ * ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
+ * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
+ * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
+ * SOFTWARE.
+ * 
+ ***************************************************************************/
 
 #include "config.h"
 
-#if HAVE_STDIO_H
 #include <stdio.h>
+
+#if HAVE_UNISTD_H
+#include <unistd.h>
 #endif
 #if HAVE_STDLIB_H
 #include <stdlib.h>
 #endif
-#if HAVE_STRING_H
-#include <string.h>
-#endif
 #if HAVE_SYS_TYPES_H
 #include <sys/types.h>
 #endif
+#if HAVE_CTYPE_H
+#include <ctype.h>
+#endif
+#if HAVE_GNUMALLOC_H
+#include <gnumalloc.h>
+#elif HAVE_MALLOC_H && !defined(_SQUID_FREEBSD_) && !defined(_SQUID_NEXT_)
+#include <malloc.h>
+#endif
+#if HAVE_MEMORY_H
+#include <memory.h>
+#endif
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
+#ifdef HAVE_STRINGS_H
+#include <strings.h>
+#endif
+#if HAVE_BSTRING_H
+#include <bstring.h>
+#endif
+#if HAVE_SYS_SOCKET_H
+#include <sys/socket.h>
+#endif
 #if HAVE_NETINET_IN_H
 #include <netinet/in.h>
 #endif
-#if HAVE_ASSERT_H
-#include <assert.h>
+#if HAVE_ARPA_INET_H
+#include <arpa/inet.h>
+#endif
+#if HAVE_SYS_TIME_H
+#include <sys/time.h>
+#endif
+#if HAVE_NETDB_H
+#include <netdb.h>
 #endif
 
 #include "asn1.h"
+#include "snmp_api_error.h"
 
-#ifdef DEBUG
-#define ERROR(string)   printf("%s(%d): %s",__FILE__, __LINE__, string);
-#else
-#define ERROR(string)
-#endif
+
+u_char *asn_build_header(u_char *data,       /* IN - ptr to start of object */
+			 int    *datalength, /* IN/OUT - # of valid bytes */
+                                             /*          left in buffer */
+			 u_char  type,       /* IN - ASN type of object */
+			 int     length)     /* IN - length of object */
+{
+  /* Truth is 0 'cause we don't know yet */
+  return(asn_build_header_with_truth(data, datalength, type, length, 0));
+}
 
 
 /*
- * asn_parse_int - pulls a long out of an ASN int type.
+ * asn_parse_int - pulls an int out of an ASN int type.
  *  On entry, datalength is input as the number of valid bytes following
  *   "data".  On exit, it is returned as the number of valid bytes
  *   following the end of this object.
