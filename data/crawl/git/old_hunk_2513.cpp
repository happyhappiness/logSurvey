		hash_pos = kh_put_sha1(writer.bitmaps, get_object_hash(*object), &hash_ret);
		if (hash_ret == 0)
			die("Duplicate entry when writing index: %s",
			    sha1_to_hex(object->sha1));

		kh_value(writer.bitmaps, hash_pos) = stored;
		display_progress(writer.progress, writer.selected_nr - i);
