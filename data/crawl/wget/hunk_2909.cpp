 static int
 cmd_spec_prefer_family (const char *com, const char *val, void *closure)
 {
-  if (0 == strcasecmp (val, "ipv4"))
-    {
-      opt.prefer_family = prefer_ipv4;
-      return 1;
-    }
-  else if (0 == strcasecmp (val, "ipv6"))
-    {
-      opt.prefer_family = prefer_ipv6;
-      return 1;
-    }
-  else if (0 == strcasecmp (val, "none"))
-    {
-      opt.prefer_family = prefer_none;
-      return 1;
-    }
-  fprintf (stderr, _("%s: %s: Invalid preferred family `%s'.\n"),
-	   exec_name, com, val);
-  return 0;
+  static const struct decode_item choices[] = {
+    { "IPv4", prefer_ipv4 },
+    { "IPv6", prefer_ipv6 },
+    { "none", prefer_none },
+  };
+  int ok = decode_string (val, choices, countof (choices),
+			  (int *) &opt.prefer_family);
+  if (!ok)
+    fprintf (stderr, _("%s: %s: Invalid value `%s'.\n"), exec_name, com, val);
+  return ok;
 }
 
 /* Set progress.type to VAL, but verify that it's a valid progress
