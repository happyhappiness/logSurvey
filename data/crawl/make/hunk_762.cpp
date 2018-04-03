     }
   strcpy (p, *argvp);
 
-  if (*funcname == 'e')
-    fatal (reading_file, "%s", msg);
+  switch (*funcname) {
+    case 'e':
+      fatal (reading_file, "%s", msg);
 
-  /* The warning function expands to the empty string.  */
-  error (reading_file, "%s", msg);
+    case 'w':
+      error (reading_file, "%s", msg);
+      break;
 
+    case 'i':
+      printf ("%s\n", msg);
+      break;
+
+    default:
+      fatal (reading_file, "Internal error: func_error: '%s'", funcname);
+  }
+
+  /* The warning function expands to the empty string.  */
   return o;
 }
 
