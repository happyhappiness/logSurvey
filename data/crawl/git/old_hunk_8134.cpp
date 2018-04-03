		num_read_blob++;
		file->ptr = read_sha1_file(o->blob_sha1, &type,
					   (unsigned long *)(&(file->size)));
		o->file = *file;
	}
	else
