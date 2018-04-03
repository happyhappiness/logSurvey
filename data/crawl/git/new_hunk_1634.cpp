
		buf = read_sha1_file(oid->hash, &type, &size);
		if (!buf)
			return err(o, _("cannot read object %s '%s'"), oid_to_hex(oid), path);
		if (type != OBJ_BLOB) {
			ret = err(o, _("blob expected for %s '%s'"), oid_to_hex(oid), path);
			goto free_buf;
		}
		if (S_ISREG(mode)) {
