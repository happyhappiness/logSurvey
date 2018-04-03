 }
 
 int
-urlcmp(const char *url1, const char *url2)
+urlcmp(const void *url1, const void *url2)
 {
     if (!url1 || !url2)
 	fatal_dump("urlcmp: Got a NULL url pointer.");
