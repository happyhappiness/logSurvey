		hash_pos = kh_put_sha1(writer.bitmaps, get_object_hash(*object), &hash_ret);
		if (hash_ret == 0)
			die("Duplicate entry when writing index: %s",
			    oid_to_hex(&object->oid));

		kh_value(writer.bitmaps, hash_pos) = stored;
		display_progress(writer.progress, writer.selected_nr - i);
