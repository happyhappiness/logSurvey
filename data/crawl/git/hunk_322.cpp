-/*
- * This code is included at the end of sha1dc/sha1.h with the
- * SHA1DC_CUSTOM_TRAILING_INCLUDE_SHA1_H macro.
- */
+/* Plumbing with collition-detecting SHA1 code */
 
-/*
- * Same as SHA1DCFinal, but convert collision attack case into a verbose die().
- */
-void git_SHA1DCFinal(unsigned char [20], SHA1_CTX *);
+#ifdef DC_SHA1_SUBMODULE
+#include "sha1collisiondetection/lib/sha1.h"
+#else
+#include "sha1dc/sha1.h"
+#endif
 
-/*
- * Same as SHA1DCUpdate, but adjust types to match git's usual interface.
- */
+void git_SHA1DCFinal(unsigned char [20], SHA1_CTX *);
 void git_SHA1DCUpdate(SHA1_CTX *ctx, const void *data, unsigned long len);
 
 #define platform_SHA_CTX SHA1_CTX