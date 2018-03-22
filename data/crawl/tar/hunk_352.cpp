       char *name;
 
       while (name = name_next (1), name)
-	ERROR ((0, 0, _("%s: Not found in archive"), name));
+	ERROR ((0, 0, _("%s: Not found in archive"),
+		quotearg_colon (name)));
     }
 }
 
