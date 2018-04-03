 #include <getopt.h>
 #endif
 
-
-#define safe_free(x)	if (x) { free(x); x = NULL; }
-
 /* A couple of harmless helper macros */
 #define SEND(X) debug("sending '%s' to squid\n",X); printf(X "\n");
 #ifdef __GNUC__
