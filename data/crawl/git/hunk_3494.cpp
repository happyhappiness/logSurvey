 		error("git upload-pack: git-pack-objects died with error.");
 		goto fail;
 	}
-	if (shallow_nr && finish_async(&rev_list))
-		goto fail;	/* error was already reported */
+	if (shallow_file) {
+		if (*shallow_file)
+			unlink(shallow_file);
+		free(shallow_file);
+	}
 
 	/* flush the data */
 	if (0 <= buffered) {