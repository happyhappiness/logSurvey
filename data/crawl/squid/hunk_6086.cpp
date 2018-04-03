 	    return file_map_bit_set(fm, suggestion);
 	}
     }
-    fatal("file_map_allocate: Exceeded filemap limit");
-    return 0;			/* NOTREACHED */
+    debug(8, 3) ("growing from file_map_allocate\n");
+    file_map_grow(fm);
+    return file_map_allocate(fm, fm->max_n_files >> 1);
 }
 
 void
