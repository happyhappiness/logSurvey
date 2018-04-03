 		struct string_list_item *item = &update->items[i];
 		if (add_file_to_cache(item->string, 0))
 			exit(128);
+		fprintf(stderr, "Staged '%s' using previous resolution.\n",
+			item->string);
 	}
 
 	if (active_cache_changed) {
