 #include <rpcsvc/ypclnt.h>
 #include <rpcsvc/yp_prot.h>
 
+#include "nis_support.h"
+
 #define NO_YPERR 0		/* There is no error */
 
-int
-get_nis_password(char *user, char *passwd, char *nisdomain, char *nismap)
+char *
+get_nis_password(char *user, char *nisdomain, char *nismap)
 {
-    char *val = NULL;
-    char *username = NULL;
+    static char *val = NULL;
+    char *password = NULL;
     int vallen, res;
 
 #ifdef DEBUG
     printf("Domain is set to %s\n", nisdomain);
     printf("YP Map is set to %s\n", nismap);
 #endif
 
+    /* Free last entry */
+    if (val) {
+	free(val);
+	val = NULL;
+    }
+
     /* Get NIS entry */
     res = yp_match(nisdomain, nismap, user, strlen(user), &val, &vallen);
 
     switch (res) {
     case NO_YPERR:
-	username = strtok(val, ":");
-	strcpy(passwd, strtok(NULL, ":"));
-	free(val);
-	break;
+	/* username = */ (void) strtok(val, ":");
+	password = strtok(NULL, ",:");
+	return password;
     case YPERR_YPBIND:
 	syslog(LOG_ERR, "Squid Authentication through ypbind failure: can't communicate with ypbind");
-	return 1;
+	return NULL;
     case YPERR_KEY:		/* No such key in map */
-	return 1;
+	return NULL;
     default:
-	return 1;
+	return NULL;
     }
-    return 0;
 }
+extern char * get_nis_password(char *user, char *nisdomain, char *nismap);