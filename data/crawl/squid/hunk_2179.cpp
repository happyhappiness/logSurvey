                 "<H2>Select URL for %s</H2>\n"
                 "<TABLE BORDER=\"0\" WIDTH=\"100%%\">\n", e->url(), e->url());
 
-    for (i = 0; i < urlcnt; i++) {
+    for (i = 0; i < urlcnt; ++i) {
         u = &urls[i];
         debugs(52, 3, "URL {" << u->url << "}");
         mb->Printf(
