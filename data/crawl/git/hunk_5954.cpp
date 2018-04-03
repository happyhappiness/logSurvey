 		error("git upload-pack: git-pack-objects died with error.");
 		goto fail;
 	}
-	if (finish_async(&rev_list))
+	if (shallow_nr && finish_async(&rev_list))
 		goto fail;	/* error was already reported */
 
 	/* flush the data */
