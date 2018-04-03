 	char packname[46];
 
 	/*
-	 * The first thing we expects from index-pack's output
+	 * The first thing we expect from index-pack's output
 	 * is "pack\t%40s\n" or "keep\t%40s\n" (46 bytes) where
 	 * %40s is the newly created pack SHA1 name.  In the "keep"
 	 * case, we need it to remove the corresponding .keep file
