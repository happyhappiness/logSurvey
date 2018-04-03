 		struct stat st;
 		struct path_list_item *p = &(list->items[i]);
 
-		if (!lstat(p->path, &st))
-			add_to_cache(p->path, &st, 0);
-		else
+		if (!lstat(p->path, &st)) {
+			if (add_to_cache(p->path, &st, 0))
+				die("updating files failed");
+		} else
 			remove_file_from_cache(p->path);
 	}
 }
