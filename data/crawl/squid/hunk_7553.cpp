     return (0);
 }
 
-static int compareLastRef(e1, e2)
-     StoreEntry **e1, **e2;
+static int
+compareLastRef(StoreEntry ** e1, StoreEntry ** e2)
 {
     if (!e1 || !e2)
 	fatal_dump(NULL);
