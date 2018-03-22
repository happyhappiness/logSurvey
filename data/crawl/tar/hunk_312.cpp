 void
 names_notfound (void)
 {
-  struct name *cursor;
-  struct name *next;
-
-  for (cursor = namelist; cursor; cursor = next)
-    {
-      next = cursor->next;
-      if (!cursor->found && !cursor->fake)
-	ERROR ((0, 0, _("%s: Not found in archive"),
-		quotearg_colon (cursor->name)));
+  struct name const *cursor;
 
-      /* We could free the list, but the process is about to die anyway, so
-	 save some CPU time.  Amigas and other similarly broken software
-	 will need to waste the time, though.  */
+  for (cursor = namelist; cursor; cursor = cursor->next)
+    if (!cursor->found && !cursor->fake)
+      ERROR ((0, 0, _("%s: Not found in archive"),
+	      quotearg_colon (cursor->name)));
 
-#ifdef amiga
-      if (!same_order_option)
-	free (cursor);
-#endif
-    }
+  /* Don't bother freeing the name list; we're about to exit.  */
   namelist = 0;
   nametail = &namelist;
 
