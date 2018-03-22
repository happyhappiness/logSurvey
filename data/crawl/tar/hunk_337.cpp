 	}
     }
 
-  ERROR ((0, 0, _("Unexpected inconsistency when making directory %s"),
-	  quote (dir_name)));
+  ERROR ((0, 0, _("%s: Unexpected inconsistency when making directory"),
+	  quotearg_colon (dir_name)));
 }
 
 /*-----------------------------------------------------------------------.
