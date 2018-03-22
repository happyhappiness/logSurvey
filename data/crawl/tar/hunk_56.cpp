 	}
     }
 }
+
+void
+label_notfound (void)
+{
+  struct name const *cursor;
+
+  if (!namelist)
+    return;
+  
+  for (cursor = namelist; cursor; cursor = cursor->next)
+    if (WASFOUND (cursor))
+      return;
+
+  if (verbose_option)
+    error (0, 0, _("Archive label mismatch"));
+  set_exit_status (TAREXIT_DIFFERS);
+
+  for (cursor = namelist; cursor; cursor = cursor->next)
+    {
+      if (regex_usage_warning (cursor->name))
+	break;
+    }
+
+  /* Don't bother freeing the name list; we're about to exit.  */
+  namelist = NULL;
+  nametail = NULL;
+
+  if (same_order_option)
+    {
+      const char *name;
+
+      while ((name = name_next (1)) != NULL
+	     && regex_usage_warning (name) == 0)
+	;
+    }
+}
 
 /* Sorting name lists.  */
 
