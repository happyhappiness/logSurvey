		num_read_blob++;
		file->ptr = read_sha1_file(o->blob_sha1, &type,
					   (unsigned long *)(&(file->size)));
		if (!file->ptr)
			die("Cannot read blob %s for path %s",
			    sha1_to_hex(o->blob_sha1),
			    o->path);
		o->file = *file;
	}
	else
