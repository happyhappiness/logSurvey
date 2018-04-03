 main(int argc, char **argv)
 {
     int auth = 0;
-    char buf[256];
+    char buf[HELPER_INPUT_BUFFER];
     char *user, *passwd, *p;
 
     setbuf(stdout, NULL);
-    while (fgets(buf, 256, stdin) != NULL) {
+    while (fgets(buf, HELPER_INPUT_BUFFER, stdin) != NULL) {
 
         if ((p = strchr(buf, '\n')) != NULL)
             *p = '\0';		/* strip \n */
 
         if ((user = strtok(buf, " ")) == NULL) {
-            printf(ERR);
+            SEND_ERR("No Username");
             continue;
         }
         if ((passwd = strtok(NULL, "")) == NULL) {
-            printf(ERR);
+            SEND_ERR("No Password");
             continue;
         }
         rfc1738_unescape(user);
