     }
 
   printf ("\n");
+
+  /* FIXME: Responsibility for deallocation should be handled by
+     whatever allocated it, wherever possible. These two lines result
+     in unnecessary strdup calls in the print_version function. */
   xfree (prefix);
   xfree (line);
 }
