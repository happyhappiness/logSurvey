 static int
 cmd_spec_header (const char *com, const char *val, void *closure)
 {
-  if (!*val)
+  if (!check_user_specified_header (val))
     {
-      /* Empty header means reset headers.  */
-      xfree_null (opt.user_header);
-      opt.user_header = NULL;
-    }
-  else
-    {
-      int i;
-
-      if (!check_user_specified_header (val))
-	{
-	  fprintf (stderr, _("%s: %s: Invalid header `%s'.\n"),
-		   exec_name, com, val);
-	  return 0;
-	}
-      i = opt.user_header ? strlen (opt.user_header) : 0;
-      opt.user_header = (char *)xrealloc (opt.user_header, i + strlen (val)
-					  + 2 + 1);
-      strcpy (opt.user_header + i, val);
-      i += strlen (val);
-      opt.user_header[i++] = '\r';
-      opt.user_header[i++] = '\n';
-      opt.user_header[i] = '\0';
+      fprintf (stderr, _("%s: %s: Invalid header `%s'.\n"),
+	       exec_name, com, val);
+      return 0;
     }
-  return 1;
+  return cmd_vector (com, val, closure);
 }
 
 static int
