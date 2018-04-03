 {
   int i;
   printf ("\nMalloc:  %d\nFree:    %d\nBalance: %d\n\n",
-	  malloc_count, free_count, malloc_count - free_count);
+          malloc_count, free_count, malloc_count - free_count);
   for (i = 0; i < SZ; i++)
     if (malloc_table[i].ptr != NULL)
       printf ("0x%0*lx: %s:%d\n", PTR_FORMAT (malloc_table[i].ptr),
-	      malloc_table[i].file, malloc_table[i].line);
+              malloc_table[i].file, malloc_table[i].line);
 }
 
 void *
