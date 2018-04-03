 	char **targets = xmalloc(nr_heads * sizeof(char*));
 	int ret, i;
 
+	if (options.depth)
+		die("dumb http transport does not support --depth");
 	for (i = 0; i < nr_heads; i++)
 		targets[i] = xstrdup(sha1_to_hex(to_fetch[i]->old_sha1));
 
