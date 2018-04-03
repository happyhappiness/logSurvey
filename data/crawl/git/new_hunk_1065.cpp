		return -1;
	}

	/*
	 * The trailing slash after the directory name is given by
	 * this function at the end. Remove duplicates.
	 */
	while (pathbuf.len && pathbuf.buf[pathbuf.len - 1] == '/')
		strbuf_setlen(&pathbuf, pathbuf.len - 1);

	if (!alt_odb_usable(&pathbuf, normalized_objdir)) {
		strbuf_release(&pathbuf);
		return -1;
	}

	entlen = st_add(pathbuf.len, 43); /* '/' + 2 hex + '/' + 38 hex + NUL */
	ent = xmalloc(st_add(sizeof(*ent), entlen));
	memcpy(ent->base, pathbuf.buf, pathbuf.len);

	ent->name = ent->base + pathbuf.len + 1;
	ent->base[pathbuf.len] = '/';
	ent->base[pathbuf.len + 3] = '/';
	ent->base[entlen-1] = 0;

	/* add the alternate entry */
	*alt_odb_tail = ent;
	alt_odb_tail = &(ent->next);
	ent->next = NULL;

	/* recursively add alternates */
	read_info_alternates(pathbuf.buf, depth + 1);

	strbuf_release(&pathbuf);
	return 0;
}
