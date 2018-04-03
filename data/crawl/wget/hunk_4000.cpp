   return 1;
 }
 
+/* Store the lockable_boolean {2, 1, 0, -1} value from VAL to CLOSURE.  COM is
+   ignored, except for error messages.  Values 2 and -1 indicate that once
+   defined, the value may not be changed by successive wgetrc files or
+   command-line arguments.
+
+   Values: 2 - Enable a particular option for good ("always")
+           1 - Enable an option ("on")
+           0 - Disable an option ("off")
+          -1 - Disable an option for good ("never") */
+static int
+cmd_lockable_boolean (const char *com, const char *val, void *closure)
+{
+  int lockable_boolean_value;
+
+  /*
+   * If a config file said "always" or "never", don't allow command line
+   * arguments to override the config file.
+   */
+  if (*(int *)closure == -1 || *(int *)closure == 2)
+    return 1;
+
+  if (!strcasecmp (val, "always")
+      || (*val == '2' && !*(val + 1)))
+    lockable_boolean_value = 2;
+  else if (!strcasecmp (val, "on")
+      || (*val == '1' && !*(val + 1)))
+    lockable_boolean_value = 1;
+  else if (!strcasecmp (val, "off")
+          || (*val == '0' && !*(val + 1)))
+    lockable_boolean_value = 0;
+  else if (!strcasecmp (val, "never")
+      || (*val == '-' && *(val + 1) == '1' && !*(val + 2)))
+    lockable_boolean_value = -1;
+  else
+    {
+      fprintf (stderr, _("%s: %s: Please specify always, on, off, "
+			 "or never.\n"),
+	       exec_name, com);
+      return 0;
+    }
+
+  *(int *)closure = lockable_boolean_value;
+  return 1;
+}
+
 /* Set the non-negative integer value from VAL to CLOSURE.  With
    incorrect specification, the number remains unchanged.  */
 static int
