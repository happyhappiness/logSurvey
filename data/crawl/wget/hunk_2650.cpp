 {
   int restrict_os = opt.restrict_files_os;
   int restrict_ctrl = opt.restrict_files_ctrl;
+  int restrict_case = opt.restrict_files_case;
 
-  const char *end = strchr (val, ',');
-  if (!end)
-    end = val + strlen (val);
+  const char *end;
 
 #define VAL_IS(string_literal) BOUNDED_EQUAL (val, end, string_literal)
 
-  if (VAL_IS ("unix"))
-    restrict_os = restrict_unix;
-  else if (VAL_IS ("windows"))
-    restrict_os = restrict_windows;
-  else if (VAL_IS ("nocontrol"))
-    restrict_ctrl = 0;
-  else
+  do
     {
-    err:
-      fprintf (stderr,
-	       _("%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"),
-	       exec_name, com, val);
-      return false;
+      end = strchr (val, ',');
+      if (!end)
+        end = val + strlen (val);
+      
+      if (VAL_IS ("unix"))
+        restrict_os = restrict_unix;
+      else if (VAL_IS ("windows"))
+        restrict_os = restrict_windows;
+      else if (VAL_IS ("lowercase"))
+        restrict_case = restrict_lowercase;
+      else if (VAL_IS ("uppercase"))
+        restrict_case = restrict_uppercase;
+      else if (VAL_IS ("nocontrol"))
+        restrict_ctrl = false;
+      else
+        {
+          fprintf (stderr,
+                   _("%s: %s: Invalid restriction `%s', use [unix|windows],[lowercase|uppercase],[nocontrol].\n"),
+                   exec_name, com, val);
+          return false;
+	}
+
+      if (*end) 
+	val = end + 1;
     }
+  while (*val && *end);
 
 #undef VAL_IS
 
-  if (*end)
-    {
-      if (!strcmp (end + 1, "nocontrol"))
-	restrict_ctrl = false;
-      else
-	goto err;
-    }
-
   opt.restrict_files_os = restrict_os;
   opt.restrict_files_ctrl = restrict_ctrl;
+  opt.restrict_files_case = restrict_case;
+  
   return true;
 }
 
