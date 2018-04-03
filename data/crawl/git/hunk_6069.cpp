 		die("--long is incompatible with --abbrev=0");
 
 	if (contains) {
-		const char **args = xmalloc((7 + argc) * sizeof(char*));
+		const char **args = xmalloc((7 + argc) * sizeof(char *));
 		int i = 0;
 		args[i++] = "name-rev";
 		args[i++] = "--name-only";
