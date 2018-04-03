 #include <string.h>
 #include <stdio.h>
 
-void define_new_function (void *, const char *, int, int, int,
-                          char *(*)(char *, char **, const char *));
-
-char *variable_buffer_output (char *, const char *, unsigned int);
-
-static char *
-func_test(char *o, char **argv, const char *funcname)
-{
-    return variable_buffer_output (o, funcname, strlen (funcname));
-}
+#include "gnumake.h"
 
 int
-testload_gmake_setup ()
+testload_gmk_setup ()
 {
-    define_new_function (0, "func-a", 1, 1, 1, func_test);
+    gmk_eval ("TESTLOAD = implicit", 0);
     return 1;
 }
 
 int
 explicit_setup ()
 {
-    define_new_function (0, "func-b", 1, 1, 1, func_test);
+    gmk_eval ("TESTLOAD = explicit", 0);
     return 1;
 }
 EOF
 close($F) or die "close: testload.c: $!\n";
 
-run_make_test('testload.so: testload.c ; @$(CC) -g -shared -fPIC -o $@ $<',
-              '', '');
+# Make sure we can compile
+run_make_test('testload.so: testload.c ; @'.$sobuild, '', '');
 
 # TEST 1
 run_make_test(q!
-all: ; @echo $(func-a foo) $(func-b bar)
+PRE := $(.LOADED)
 load testload.so
+POST := $(.LOADED)
+all: ; @echo pre=$(PRE) post=$(POST) $(TESTLOAD)
 !,
-              '', "func-a\n");
+              '', "pre= post=testload.so implicit\n");
 
 # TEST 2
-# Load a different function
+# Load using an explicit function
 run_make_test(q!
-all: ; @echo $(func-a foo) $(func-b bar)
+PRE := $(.LOADED)
 load ./testload.so(explicit_setup)
+POST := $(.LOADED)
+all: ; @echo pre=$(PRE) post=$(POST) $(TESTLOAD)
 !,
-              '', "func-b\n");
-
-# TEST 3
-# Verify the .LOADED variable
-run_make_test(q!
-all: ; @echo $(filter testload.so,$(.LOADED)) $(func-a foo) $(func-b bar)
-load testload.so(explicit_setup)
-!,
-              '', "testload.so func-b\n");
+              '', "pre= post=testload.so explicit\n");
 
 # TEST 4
 # Check multiple loads
 run_make_test(q!
-all: ; @echo $(filter testload.so,$(.LOADED)) $(func-a foo) $(func-b bar)
+PRE := $(.LOADED)
 load ./testload.so
 load testload.so(explicit_setup)
+POST := $(.LOADED)
+all: ; @echo pre=$(PRE) post=$(POST) $(TESTLOAD)
 !,
-              '', "testload.so func-a\n");
+              '', "pre= post=testload.so implicit\n");
 
 # TEST 5
 # Check auto-rebuild of loaded file that's out of date
