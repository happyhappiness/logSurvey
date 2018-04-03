 };
 
 char *ntlmGetString(ntlmhdr * hdr, strhdr * str, int flags);
-void ntlmMakeChallenge(struct ntlm_challenge *chal);
+void ntlmMakeChallenge(struct ntlm_challenge *chal, int32_t flags);
 int ntlmCheckHeader(ntlmhdr * hdr, int type);
 int ntlmCheckNegotiation(struct ntlm_negotiate *neg);
 int ntlmAuthenticate(struct ntlm_authenticate *neg);
 
+#define safe_free(x)	if (x) { free(x); x = NULL; }
+
+#undef debug
+
+/************* CONFIGURATION ***************/
+/*
+ * define this if you want debugging
+ */
+#ifndef DEBUG
+#define DEBUG
+#endif
+
+#define FAIL_DEBUG 0
+
+/************* END CONFIGURATION ***************/
+
+#include <sys/types.h>
+
+extern int debug_enabled;
+#if FAIL_DEBUG
+extern int fail_debug_enabled;
+#endif
+
+/* Debugging stuff */
+
+#ifdef __GNUC__			/* this is really a gcc-ism */
+#ifdef DEBUG
+#include <stdio.h>
+#include <unistd.h>
+static char *__foo;
+#define debug(X...) if (debug_enabled) { \
+                    fprintf(stderr,"ntlm-auth[%d](%s:%d): ", getpid(), \
+                    ((__foo=strrchr(__FILE__,'/'))==NULL?__FILE__:__foo+1),\
+                    __LINE__);\
+                    fprintf(stderr,X); }
+#else /* DEBUG */
+#define debug(X...)		/* */
+#endif /* DEBUG */
+#else /* __GNUC__ */
+static void
+debug(char *format,...)
+{
+#ifdef DEBUG
+#ifdef _SQUID_MSWIN_
+#if FAIL_DEBUG
+    if (debug_enabled || fail_debug_enabled) {
+#else
+    if (debug_enabled) {
+#endif
+	va_list args;
+
+	va_start(args, format);
+	fprintf(stderr, "ntlm-auth[%d]: ", getpid());
+	vfprintf(stderr, format, args);
+	va_end(args);
+#if FAIL_DEBUG
+	fail_debug_enabled = 0;
+#endif
+    }
+#endif /* _SQUID_MSWIN_ */
+#endif /* DEBUG */
+}
+#endif /* __GNUC__ */
+
+
+/* A couple of harmless helper macros */
+#define SEND(X) debug("sending '%s' to squid\n",X); printf(X "\n");
+#ifdef __GNUC__
+#define SEND2(X,Y...) debug("sending '" X "' to squid\n",Y); printf(X "\n",Y);
+#else
+/* no gcc, no debugging. varargs macros are a gcc extension */
+#define SEND2(X,Y) debug("sending '" X "' to squid\n",Y); printf(X "\n",Y);
+#endif
+
 #endif /* _NTLM_H_ */