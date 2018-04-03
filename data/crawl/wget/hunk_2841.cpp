     {
       free_vec (opt.user_headers);
       opt.user_headers = NULL;
-      return 1;
+      return true;
     }
 
   if (!check_user_specified_header (val))
     {
       fprintf (stderr, _("%s: %s: Invalid header `%s'.\n"),
 	       exec_name, com, val);
-      return 0;
+      return false;
     }
   opt.user_headers = vec_append (opt.user_headers, val);
-  return 1;
+  return true;
 }
 
-static int
+static bool
 cmd_spec_htmlify (const char *com, const char *val, void *place_ignored)
 {
   int flag = cmd_boolean (com, val, &opt.htmlify);
   if (flag && !opt.htmlify)
-    opt.remove_listing = 0;
+    opt.remove_listing = false;
   return flag;
 }
 
 /* Set the "mirror" mode.  It means: recursive download, timestamping,
    no limit on max. recursion depth, and don't remove listings.  */
 
-static int
+static bool
 cmd_spec_mirror (const char *com, const char *val, void *place_ignored)
 {
   int mirror;
 
   if (!cmd_boolean (com, val, &mirror))
-    return 0;
+    return false;
   if (mirror)
     {
-      opt.recursive = 1;
+      opt.recursive = true;
       if (!opt.no_dirstruct)
-	opt.dirstruct = 1;
-      opt.timestamping = 1;
+	opt.dirstruct = true;
+      opt.timestamping = true;
       opt.reclevel = INFINITE_RECURSION;
-      opt.remove_listing = 0;
+      opt.remove_listing = false;
     }
-  return 1;
+  return true;
 }
 
 /* Validate --prefer-family and set the choice.  Allowed values are
    "IPv4", "IPv6", and "none".  */
 
-static int
+static bool
 cmd_spec_prefer_family (const char *com, const char *val, void *place_ignored)
 {
   static const struct decode_item choices[] = {
