 #include "squid.h"
 #include "helpers/defines.h"
 
-#include <cstring>
+#include <iostream>
+#include <string>
 
 /**
  * options:
  * -d enable debugging.
  * -h interface help.
  */
-char *program_name = NULL;
+std::string program_name;
 
 static void
 usage(void)
 {
-    fprintf(stderr,
-            "Usage: %s [-d] [-v] [-h]\n"
-            " -d  enable debugging.\n"
-            " -h  this message\n\n",
-            program_name);
+    std::cerr <<
+            "Usage: " << program_name << " [-d] [-h]" << std::endl <<
+            " -d  enable debugging." << std::endl <<
+            " -h  this message" << std::endl << std::endl;
 }
 
 static void
