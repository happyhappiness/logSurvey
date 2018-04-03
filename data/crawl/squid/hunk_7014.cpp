     debug(20, 3) ("  %6d were released\n", n_released);
 }
 
-static int
-compareLastRef(StoreEntry ** e1, StoreEntry ** e2)
-{
-    if (!e1 || !e2)
-	fatal_dump(NULL);
-    if ((*e1)->lastref > (*e2)->lastref)
-	return (1);
-    if ((*e1)->lastref < (*e2)->lastref)
-	return (-1);
-    return (0);
-}
-
-/* returns the bucket number to work on,
- * pointer to next bucket after each calling
- */
-static unsigned int
-storeGetBucketNum(void)
-{
-    static unsigned int bucket = 0;
-    if (bucket >= store_buckets)
-	bucket = 0;
-    return (bucket++);
-}
 /* The maximum objects to scan for maintain storage space */
 #define MAINTAIN_MAX_SCAN	1024
 #define MAINTAIN_MAX_REMOVE	64