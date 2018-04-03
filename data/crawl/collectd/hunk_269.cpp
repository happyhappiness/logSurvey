 
     if (! value) {
       fprintf (stderr, "ERROR: flush: Invalid option ``%s''.\n", argv[i]);
-      return (-1);
+      BAIL_OUT (-1);
     }
 
     *value = '\0';
