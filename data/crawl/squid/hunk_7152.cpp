 static void
 parse_regexlist(relist ** var)
 {
-    aclParseRegexList(var, 0);
+    aclParseRegexList(var);
 }
 
 static void
-dump_regexlist_icase(relist * var)
+free_regexlist(relist ** var)
 {
-    debug(0,0)("XXX need to fix\n");
+    aclDestroyRegexList(*var);
+    *var = NULL;
 }
 
 static void
-parse_regexlist_icase(relist ** var)
-{
-    aclParseRegexList(var, 1);
-}
-
-static void
-dump_string(char var[])
+dump_string(char *var)
 {
     printf("%s", var);
 }
 
 static void
-parse_string(char *var[])
+parse_string(char **var)
 {
     char *token = strtok(NULL, w_space);
-
     safe_free(*var);
     if (token == NULL)
 	self_destruct();
     *var = xstrdup(token);
 }
 
+static void
+free_string(char **var)
+{
+	xfree(*var);
+	*var = NULL;
+}
 static void
 dump_string_optional(const char *var)
 {
     printf("%s", var);
 }
 
 static void
-parse_string_optional(char *volatile *var)
+parse_volatile_string(char *volatile *var)
 {
     char *token = strtok(NULL, null_string);
-
     safe_free(*var);
     if (token == NULL) {
 	*var = NULL;
