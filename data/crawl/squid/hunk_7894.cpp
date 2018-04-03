     int i;
 
     if (!e)
-	fatal_dump("storeFreeEntry: NULL Entry\n");
+	fatal_dump("storeFreeEntry: NULL Entry");
 
     debug(20, 5, "storeFreeEntry: Freeing %s\n", e->url);
 
