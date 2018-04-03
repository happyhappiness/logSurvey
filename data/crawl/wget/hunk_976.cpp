 {
   /*printf("[ current = `%s'\n", charset);*/
   if (current)
-    xfree (current);
+    {
+      /* Do nothing if already equal */
+      if (!strcasecmp (current, charset))
+        return;
+      xfree (current);
+    }
 
   current = charset ? xstrdup (charset) : NULL;
 }
 
 void set_current_as_locale (void)
 {
+  /* sXXXav : assert opt.locale NULL ? */
   /*printf("[ current = locale = `%s'\n", opt.locale);*/
   if (current)
-    xfree (current);
+    {
+      if (!strcasecmp (current, opt.locale))
+        return;
+      xfree (current);
+    }
 
-  /* sXXXav : assert opt.locale NULL ? */
   current = xstrdup (opt.locale);
 }
 
