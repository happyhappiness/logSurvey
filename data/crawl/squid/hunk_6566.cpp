 	}
     }
     fprintf(stderr, "%s:%d: scanned (size: %d bytes)\n", 
-	fname, count, count*sizeof(CacheEntry));
+	fname, count, (int)(count*sizeof(CacheEntry)));
     return count;
 }
 
