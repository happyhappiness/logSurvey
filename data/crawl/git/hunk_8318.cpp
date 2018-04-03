 			continue;
 		if (S_ISDIR(entry.mode))
 			obj = &lookup_tree(entry.sha1)->object;
-		else
+		else if (S_ISREG(entry.mode) || S_ISLNK(entry.mode))
 			obj = &lookup_blob(entry.sha1)->object;
+		else {
+			warning("in tree %s: entry %s has bad mode %.6o\n",
+			     sha1_to_hex(item->object.sha1), entry.path, entry.mode);
+			obj = lookup_unknown_object(entry.sha1);
+		}
 		refs->ref[i++] = obj;
 	}
 	set_object_refs(&item->object, refs);