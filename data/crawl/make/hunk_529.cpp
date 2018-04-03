   if (len > 255)
     fatal (flocp, _("Function name too long: %s\n"), name);
   if (min < 0 || min > 255)
-    fatal (flocp, _("Invalid minimum argument count (%d) for function %s%s\n"),
+    fatal (flocp, _("Invalid minimum argument count (%d) for function %s\n"),
            min, name);
   if (max < 0 || max > 255 || max < min)
-    fatal (flocp, _("Invalid maximum argument count (%d) for function %s%s\n"),
+    fatal (flocp, _("Invalid maximum argument count (%d) for function %s\n"),
            max, name);
 
   ent->name = name;
