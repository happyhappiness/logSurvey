   expanded_name = allocated_variable_expand (name);
 
   if (expanded_name[0] == '\0')
-    {
-      if (filename == 0)
-	fatal ("empty variable name");
-      else
-	makefile_fatal (filename, lineno, "empty variable name");
-    }
+    makefile_fatal (filename, lineno, "empty variable name");
 
   /* Calculate the variable's new value in VALUE.  */
 
   switch (flavor)
     {
-    case bogus:
+    case f_bogus:
       /* Should not be possible.  */
       abort ();
-      return 0;
-    case simple:
+    case f_simple:
       /* A simple variable definition "var := value".  Expand the value.  */
       value = variable_expand (p);
       break;
-    case recursive:
+    case f_conditional:
+      /* A conditional variable definition "var ?= value".
+         The value is set IFF the variable is not defined yet. */
+      v = lookup_variable(expanded_name, strlen(expanded_name));
+      if (v)
+        {
+          free(expanded_name);
+          return v;
+        }
+      /* FALLTHROUGH */
+    case f_recursive:
       /* A recursive variable definition "var = value".
 	 The value is used verbatim.  */
       value = p;
       break;
-    case append:
+    case f_append:
       /* An appending variable definition "var += value".
 	 Extract the old value and append the new one.  */
       v = lookup_variable (expanded_name, strlen (expanded_name));
