 
 #include "digest_common.h"
 #include "text_backend.h"
+#include "ldap_backend.h"
+#define PROGRAM_NAME "digest_pw_auth"
+char *backend;
+
+
+void
+usage()
+{
+    fprintf(stderr, "\n\t\tYou need at least to specify the backend database\n");
+    fprintf(stderr, "\t\t%s -D LDAP or file\n", PROGRAM_NAME);
+    exit(1);
+}
+
+void
+GetHHA1(RequestData * requestData)
+{
+    if (strcmp(backend, "LDAP") == 0)
+	LDAPHHA1(requestData);
+    else if (strcmp(backend, "file") == 0)
+	TextHHA1(requestData);
+}
 
 static void
-ParseBuffer(char *buf, RequestData *requestData)
+ParseBuffer(char *buf, RequestData * requestData)
 {
     char *p;
     requestData->parsed = 0;
