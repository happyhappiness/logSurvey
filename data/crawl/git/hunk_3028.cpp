 		}
 	}
 
-	/*
-	 * Some of the paths that had conflicts earlier might have
-	 * been resolved by the user.  Others may be similar to a
-	 * conflict already that was resolved before.
-	 */
-	for (i = 0; i < rr->nr; i++) {
-		int ret;
-		const char *path = rr->items[i].string;
-		const char *name = (const char *)rr->items[i].util;
-
-		/* Is there a recorded resolution we could attempt to apply? */
-		if (has_rerere_resolution(name)) {
-			if (merge(name, path))
-				continue;
-
-			if (rerere_autoupdate)
-				string_list_insert(&update, path);
-			else
-				fprintf(stderr,
-					"Resolved '%s' using previous resolution.\n",
-					path);
-			goto mark_resolved;
-		}
-
-		/* Let's see if the user has resolved it. */
-		ret = handle_file(path, NULL, NULL);
-		if (ret)
-			continue;
-
-		copy_file(rerere_path(name, "postimage"), path, 0666);
-		fprintf(stderr, "Recorded resolution for '%s'.\n", path);
-	mark_resolved:
-		free(rr->items[i].util);
-		rr->items[i].util = NULL;
-	}
+	for (i = 0; i < rr->nr; i++)
+		do_rerere_one_path(&rr->items[i], &update);
 
 	if (update.nr)
 		update_paths(&update);