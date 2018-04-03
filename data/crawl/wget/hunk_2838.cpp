     {
       fprintf (stderr, _("%s: %s: Invalid byte value `%s'\n"),
 	       exec_name, com, val);
-      return 0;
+      return false;
     }
   *(wgint *)place = (wgint)byte_value;
-  return 1;
+  return true;
 }
 
 /* Like cmd_bytes, but PLACE is interpreted as a pointer to
