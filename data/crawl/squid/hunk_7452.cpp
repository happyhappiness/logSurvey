 }
 
 int
-urlcmp(char *url1, char *url2)
+urlcmp(const char *url1, const char *url2)
 {
     if (!url1 || !url2)
 	fatal_dump("urlcmp: Got a NULL url pointer.");