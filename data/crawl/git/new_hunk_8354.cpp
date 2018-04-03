		z_stream stream;
		unsigned long maxsize;
		void *out;
		if (!usable_delta) {
			buf = read_sha1_file(entry->sha1, &obj_type, &size);
			if (!buf)
				die("unable to read %s", sha1_to_hex(entry->sha1));
		} else if (entry->delta_data) {
			size = entry->delta_size;
			buf = entry->delta_data;
			entry->delta_data = NULL;
			obj_type = (allow_ofs_delta && entry->delta->offset) ?
				OBJ_OFS_DELTA : OBJ_REF_DELTA;
		} else {
			buf = read_sha1_file(entry->sha1, &type, &size);
			if (!buf)
				die("unable to read %s", sha1_to_hex(entry->sha1));
			buf = delta_against(buf, size, entry);
			size = entry->delta_size;
			obj_type = (allow_ofs_delta && entry->delta->offset) ?
				OBJ_OFS_DELTA : OBJ_REF_DELTA;
		}
		/* compress the data to store and put compressed length in datalen */
		memset(&stream, 0, sizeof(stream));