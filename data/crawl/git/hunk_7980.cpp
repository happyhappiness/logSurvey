 			     const char *c_meta, const char *c_reset)
 {
 	printf("%s%s", c_meta, prefix);
-	if (quote_c_style(path, NULL, NULL, 0))
-		quote_c_style(path, NULL, stdout, 0);
-	else
-		printf("%s", path);
+	quote_c_style(path, NULL, stdout, 0);
 	printf("%s\n", c_reset);
 }
 
