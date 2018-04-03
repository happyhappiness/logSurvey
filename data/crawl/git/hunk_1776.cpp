 		struct strbuf *base,
 		const char *pathname, unsigned mode, int stage, void *context)
 {
-	printf("%s%s\n", pathname, S_ISDIR(mode) ? "/" : "");
+	FILE *file = context;
+	fprintf(file, "%s%s\n", pathname, S_ISDIR(mode) ? "/" : "");
 	return 0;
 }
 
