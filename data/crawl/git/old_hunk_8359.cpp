		z_stream stream;
		unsigned long maxsize;
		void *out;
		buf = read_sha1_file(entry->sha1, &type, &size);
		if (!buf)
			die("unable to read %s", sha1_to_hex(entry->sha1));
		if (size != entry->size)
			die("object %s size inconsistency (%lu vs %lu)",
			    sha1_to_hex(entry->sha1), size, entry->size);
		if (usable_delta) {
			buf = delta_against(buf, size, entry);
			size = entry->delta_size;
			obj_type = (allow_ofs_delta && entry->delta->offset) ?
				OBJ_OFS_DELTA : OBJ_REF_DELTA;
		} else {
			/*
			 * recover real object type in case
			 * check_object() wanted to re-use a delta,
			 * but we couldn't since base was in previous split pack
			 */
			obj_type = type;
		}
		/* compress the data to store and put compressed length in datalen */
		memset(&stream, 0, sizeof(stream));
