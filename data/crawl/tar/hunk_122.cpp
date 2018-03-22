 
   if (same_order_option)
     {
-      char *name;
+      const char *name;
 
       while ((name = name_next (1)) != NULL)
-	ERROR ((0, 0, _("%s: Not found in archive"),
-		quotearg_colon (name)));
+	{
+	  regex_usage_warning (name);
+	  ERROR ((0, 0, _("%s: Not found in archive"),
+		  quotearg_colon (name)));
+	}
     }
 }
 
