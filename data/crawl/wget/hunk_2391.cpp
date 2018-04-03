 
  retry:
   if (!al)
-    return E_HOST;
+    {
+      logprintf (LOG_NOTQUIET,
+                 _("%s: unable to resolve host address `%s'\n"),
+                 exec_name, host);
+      return E_HOST;
+    }
 
   address_list_get_bounds (al, &start, &end);
   for (i = start; i < end; i++)
