     }
 }
 
-int urlcmp(url1, url2)
-     char *url1, *url2;
+int
+urlcmp(char *url1, char *url2)
 {
     if (!url1 || !url2)
 	fatal_dump("urlcmp: Got a NULL url pointer.");
