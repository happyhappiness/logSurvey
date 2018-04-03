 	    return file_map_bit_set(fm, suggestion);
 	}
     }
-    fatal_dump("file_map_allocate: Exceeded filemap limit");
+    fatal("file_map_allocate: Exceeded filemap limit");
     return 0;			/* NOTREACHED */
 }
 
