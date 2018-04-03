 	}
 
 	strbuf_add_absolute_path(&objdirbuf, get_object_directory());
-	normalize_path_copy(objdirbuf.buf, objdirbuf.buf);
+	if (strbuf_normalize_path(&objdirbuf) < 0)
+		die("unable to normalize object directory: %s",
+		    objdirbuf.buf);
 
 	alt_copy = xmemdupz(alt, len);
 	string_list_split_in_place(&entries, alt_copy, sep, -1);
