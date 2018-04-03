 		const char *entry = entries.items[i].string;
 		if (entry[0] == '\0' || entry[0] == '#')
 			continue;
-		if (!is_absolute_path(entry) && depth) {
-			error("%s: ignoring relative alternate object store %s",
-					relative_base, entry);
-		} else {
-			link_alt_odb_entry(entry, relative_base, depth, objdirbuf.buf);
-		}
+		link_alt_odb_entry(entry, relative_base, depth, objdirbuf.buf);
 	}
 	string_list_clear(&entries, 0);
 	free(alt_copy);
