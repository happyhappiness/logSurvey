      char *url1, *url2;
 {
     if (!url1 || !url2)
-	death();
+	fatal_dump("urlcmp: Got a NULL url pointer.\n");
     return (strcmp(url1, url2));
 }
 
