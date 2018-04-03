	}

	strbuf_add_absolute_path(&objdirbuf, get_object_directory());
	if (strbuf_normalize_path(&objdirbuf) < 0)
		die("unable to normalize object directory: %s",
		    objdirbuf.buf);

	alt_copy = xmemdupz(alt, len);
	string_list_split_in_place(&entries, alt_copy, sep, -1);
