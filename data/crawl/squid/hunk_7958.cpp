 	Config.singleParentBypass = 1;
 }
 
-void parseCacheNeighborObjLine(line_in)
-     char *line_in;
-{
-    printf("WARNING: 'cache_neighbor_obj' is no longer supported.  Please\n");
-    printf("         use 'proxy-only' on the 'cache_host' line instead now.\n");
-    fflush(stdout);
-}
-
-void parseBehindFirewallLine(line_in)
+static void parseDebugOptionsLine(line_in)
      char *line_in;
 {
-    printf("WARNING: 'behind_firewall' is no longer supported.  Please\n");
-    printf("         use the 'inside_firewall' and 'local_domain' lines\n");
-    printf("         instead now.\n");
-    fflush(stdout);
-}
-
-void parseDirectFetchLine(line_in)
-     char *line_in;
-{
-    printf("WARNING: 'direct_fetch' is no longer supported.  Please\n");
-    printf("         use the 'inside_firewall' and 'local_domain' lines\n");
-    printf("         instead now.\n");
-    fflush(stdout);
+    char *token;
+    token = strtok(NULL, "");	/* Note "", don't separate these */
+    safe_free(Config.debugOptions);
+    if (token == (char *) NULL) {
+	Config.debugOptions = NULL;
+	return;
+    }
+    Config.debugOptions = xstrdup(token);
 }
 
-/* Maybe a bit heavy handed, but parser is immune to virtually every sane
- * persons definition of white space */
-
 int parseConfigFile(file_name)
      char *file_name;
 {
-    FILE *fp = fopen(file_name, "r");
-    char *token, tmp_line[BUFSIZ];
-    char line_in[BUFSIZ];
-    char fatal_str[4096];
+    FILE *fp = NULL;
+    char *token = NULL;
+    static char tmp_line[BUFSIZ];
+    static char line_in[BUFSIZ];
+    static char fatal_str[4096];
 
     /* Initialize a few global strings, in case they aren't user defined */
 
     configSetFactoryDefaults();
 
-    if (fp == NULL) {
+    if ((fp = fopen(file_name, "r")) == NULL) {
 	sprintf(fatal_str, "Unable to open configuration file: %s", file_name);
 	fatal(fatal_str);
     }
