 {
 	if (pack_edges)
 		fclose(pack_edges);
-	pack_edges = fopen(edges, "a");
-	if (!pack_edges)
-		die_errno("Cannot open '%s'", edges);
+	pack_edges = xfopen(edges, "a");
 }
 
 static int parse_one_option(const char *option)
