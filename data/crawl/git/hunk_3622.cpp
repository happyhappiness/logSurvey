 	if (!work_tree)
 		goto out;
 
-	if (!the_index.initialized)
-		if (read_cache() < 0)
-			die("index file corrupt");
+	if (read_cache() < 0)
+		die("index file corrupt");
 
 	argv_array_push(&argv, "fetch");
 	for (i = 0; i < options->argc; i++)