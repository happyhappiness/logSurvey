		unsigned long size;

		if (S_ISGITLINK(mode))
			/*
			 * We may later decide to recursively descend into
			 * the submodule directory and update its index
			 * and/or work tree, but we do not do that now.
			 */
			goto update_index;

		buf = read_sha1_file(sha, &type, &size);
		if (!buf)
