 	}
 
 	for (i = 0; i < dir->nr; i++)
-		if (add_file_to_cache(dir->entries[i]->name, flags)) {
+		if (add_file_to_index(&the_index, dir->entries[i]->name,
+				flags, force_mode)) {
 			if (!ignore_add_errors)
 				die(_("adding files failed"));
 			exit_status = 1;
