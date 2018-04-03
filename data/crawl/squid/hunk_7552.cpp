     return 0;
 }
 
-static int compareSize(e1, e2)
-     StoreEntry **e1, **e2;
+static int
+compareSize(StoreEntry ** e1, StoreEntry ** e2)
 {
     if (!e1 || !e2)
 	fatal_dump(NULL);
