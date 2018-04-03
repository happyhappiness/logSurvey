     } else {
 	fprintf(stderr, "No memory leaks detected\n");
     }
-}
-void
-xmalloc_dump_map(void)
-{
-    int B, I;
-    fprintf(stderr, "----- Memory map ----\n");
-    for (B = 0; B < DBG_ARRY_BKTS; B++) {
-	for (I = 0; I < DBG_ARRY_SZ; I++) {
-	    if (malloc_ptrs[B][I]) {
-		printf("%p %s:%d size %d allocation %d references %d\n",
-		    malloc_ptrs[B][I], malloc_file[B][I], malloc_line[B][I],
-		    malloc_size[B][I], malloc_count[B][I],
-		    malloc_refs[B][I] & (XMALLOC_LEAK_CHECKED - 1));
-	    }
-	}
-    }
     fprintf(stderr, "----------------------\n");
 }
 #endif /* XMALLOC_TRACE */
