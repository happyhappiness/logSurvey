     return 0;
 }
 
-int compareSize(e1, e2)
+static int compareSize(e1, e2)
      StoreEntry **e1, **e2;
 {
-    if (!e1 || !e2) {
-	debug(20, 1, "compareSize: Called with at least one null argument, shouldn't happen.\n");
-	return 0;
-    }
+    if (!e1 || !e2)
+	fatal_dump(NULL);
     if ((*e1)->mem_obj->e_current_len > (*e2)->mem_obj->e_current_len)
 	return (1);
-
     if ((*e1)->mem_obj->e_current_len < (*e2)->mem_obj->e_current_len)
 	return (-1);
-
     return (0);
 }
 
-int compareLastRef(e1, e2)
+static int compareLastRef(e1, e2)
      StoreEntry **e1, **e2;
 {
     if (!e1 || !e2)
 	fatal_dump(NULL);
-
     if ((*e1)->lastref > (*e2)->lastref)
 	return (1);
-
     if ((*e1)->lastref < (*e2)->lastref)
 	return (-1);
-
     return (0);
 }
 
