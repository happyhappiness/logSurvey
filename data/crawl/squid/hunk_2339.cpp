 #include "ConfigParser.h"
 #include "wordlist.h"
 
-void
-self_destruct(void)
-{
-    /*    fatalf("Bungled %s line %d: %s",
-               cfg_filename, config_lineno, config_input_line);*/
-    fatalf("bungled line");
-}
-
-void
-parse_int(int *var)
-{
-    fatal("not implemented 1");
-}
-
-void
-parse_onoff(int *var)
-{
-    fatal("not implemented 2");
-}
-
-void
-parse_eol(char *volatile *var)
+#define STUB_API "cache_cf.cc"
+#include "tests/STUB.h"
+
+void self_destruct(void) STUB
+void parse_int(int *var) STUB
+void parse_onoff(int *var) STUB
+void parse_eol(char *volatile *var) STUB
+#if 0
 {
     unsigned char *token = (unsigned char *) strtok(NULL, null_string);
     safe_free(*var);
