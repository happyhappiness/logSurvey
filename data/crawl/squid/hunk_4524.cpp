 #include "text_backend.h"
 #define PROGRAM_NAME "digest_pw_auth"
 
-
-void
-usage()
-{
-    fprintf(stderr, "\n\t\tYou need at least to specify the backend database\n");
-    fprintf(stderr, "\t\t%s -D LDAP or file\n", PROGRAM_NAME);
-    exit(1);
-}
-
-void
+static void
 GetHHA1(RequestData * requestData)
 {
     TextHHA1(requestData);
