   while (n != p);
 
   p = strlen (keyword) + n + 2;
+  size = p;
+  if (size != p)
+    {
+      ERROR ((0, 0,
+        _("Generated keyword/value pair is too long (keyword=%s, length=%s"),
+	      keyword, nbuf));
+      obstack_free (extended_header.stk, obstack_finish (extended_header.stk));
+      return false;
+    }
   x_obstack_blank (&extended_header, p);
   x_obstack_1grow (&extended_header, '\n');
   cp = obstack_next_free (extended_header.stk) - string_length - p - 1;
