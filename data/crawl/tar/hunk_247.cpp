     {
       char *name;
 
-      while (name = name_next (1), name)
+      while ((name = name_next (1)) != NULL)
 	ERROR ((0, 0, _("%s: Not found in archive"),
 		quotearg_colon (name)));
     }
