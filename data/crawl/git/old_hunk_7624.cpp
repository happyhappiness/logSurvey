		void *buf;
		unsigned long size;

		buf = read_sha1_file(sha, &type, &size);
		if (!buf)
			die("cannot read object %s '%s'", sha1_to_hex(sha), path);
