 	xfree(*var);
 	*var = NULL;
 }
-static void
-dump_string_optional(const char *var)
-{
-    printf("%s", var);
-}
 
 static void
-parse_volatile_string(char *volatile *var)
+parse_eol(char *volatile *var)
 {
     char *token = strtok(NULL, null_string);
     safe_free(*var);
-    if (token == NULL) {
-	*var = NULL;
-	return;
-    }
+    if (token == NULL)
+	self_destruct();
     *var = xstrdup(token);
 }
 
 static void
-dump_time_min(int var)
-{
-    printf("%d", var / 60);
-}
-
-static void
-parse_time_min(int *var)
+dump_time_t(time_t var)
 {
-    parseTimeLine(var, T_MINUTE_STR);
+    printf("%d", (int) var);
 }
 
 static void
-dump_time_sec(int var)
+parse_time_t(time_t *var)
 {
-    printf("%d", var);
+    parseTimeLine(var, T_SECOND_STR);
 }
 
 static void
-parse_time_sec(int *var)
+free_time_t(time_t *var)
 {
-    parseTimeLine(var, T_SECOND_STR);
+	*var = 0;
 }
+	
 
 static void
 dump_ushort(u_short var)
