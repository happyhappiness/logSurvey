 	FILE *fp = fopen(filename, "r");
 
 	if (!fp)
-		die("Could not open file '%s': %s", filename, strerror(errno));
+		die_errno("Could not open file '%s'", filename);
 
 	while (strbuf_getline(&str, fp, '\n') != EOF) {
 		char *quoted;
