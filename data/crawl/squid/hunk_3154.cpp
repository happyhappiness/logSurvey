 }
 
 static int
-build_filter(char *filter, int size, const char *template, const char *user, const char *group)
+build_filter(char *filter, int size, const char *templ, const char *user, const char *group)
 {
     int n;
-    while (*template && size > 0) {
-        switch (*template) {
+    while (*templ && size > 0) {
+        switch (*templ) {
         case '%':
-            template++;
-            switch (*template) {
+            templ++;
+            switch (*templ) {
             case 'u':
             case 'v':
-                template++;
+                templ++;
                 n = ldap_escape_value(filter, size, user);
                 size -= n;
                 filter += n;
                 break;
             case 'g':
             case 'a':
-                template++;
+                templ++;
                 n = ldap_escape_value(filter, size, group);
                 size -= n;
                 filter += n;
                 break;
             default:
-                fprintf(stderr, "ERROR: Unknown filter template string %%%c\n", *template);
+                fprintf(stderr, "ERROR: Unknown filter template string %%%c\n", *templ);
                 return 1;
                 break;
             }
             break;
         case '\\':
-            template++;
-            if (*template) {
-                *filter++ = *template++;
+            templ++;
+            if (*templ) {
+                *filter++ = *templ++;
                 size--;
             }
             break;
         default:
-            *filter++ = *template++;
+            *filter++ = *templ++;
             size--;
             break;
         }
