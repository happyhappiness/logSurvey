			obj_type = (allow_ofs_delta && entry->delta->idx.offset) ?
				OBJ_OFS_DELTA : OBJ_REF_DELTA;
		} else {
			buf = read_sha1_file(entry->idx.sha1, &type, &size);
			if (!buf)
				die("unable to read %s", sha1_to_hex(entry->idx.sha1));
			buf = delta_against(buf, size, entry);
			size = entry->delta_size;
			obj_type = (allow_ofs_delta && entry->delta->idx.offset) ?
				OBJ_OFS_DELTA : OBJ_REF_DELTA;