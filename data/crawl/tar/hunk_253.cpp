   if (status < 0)
     write_error (name);
   else
-    ERROR ((0, 0, _("%s: Wrote only %lu of %lu bytes"),
+    ERROR ((0, 0,
+	    ngettext ("%s: Wrote only %lu of %lu byte",
+		      "%s: Wrote only %lu of %lu bytes",
+		      record_size),
 	    name, (unsigned long) status, (unsigned long) record_size));
 }
 
