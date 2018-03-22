   struct name const *cursor;
 
   for (cursor = namelist; cursor; cursor = cursor->next)
-    if (!cursor->found && !cursor->fake)
-      ERROR ((0, 0, _("%s: Not found in archive"),
-	      quotearg_colon (cursor->name)));
-
+    if (!WASFOUND(cursor) && !cursor->fake)
+      {
+	if (cursor->found_count == 0)
+	  ERROR ((0, 0, _("%s: Not found in archive"),
+		  quotearg_colon (cursor->name)));
+	else
+	  ERROR ((0, 0, _("%s: Required occurence not found in archive"),
+		  quotearg_colon (cursor->name)));
+      }
+  
   /* Don't bother freeing the name list; we're about to exit.  */
   namelist = 0;
   nametail = &namelist;
