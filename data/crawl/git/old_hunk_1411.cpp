			goto update_index;
		}

		buf = read_sha1_file(sha, &type, &size);
		if (!buf)
			die(_("cannot read object %s '%s'"), sha1_to_hex(sha), path);
		if (type != OBJ_BLOB)
			die(_("blob expected for %s '%s'"), sha1_to_hex(sha), path);
		if (S_ISREG(mode)) {
			struct strbuf strbuf = STRBUF_INIT;
			if (convert_to_working_tree(path, buf, size, &strbuf)) {
