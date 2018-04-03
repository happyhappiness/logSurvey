		return -1;
	}

	pfxlen = strlen(pathbuf.buf);

	/*
	 * The trailing slash after the directory name is given by
	 * this function at the end. Remove duplicates.
	 */
	while (pfxlen && pathbuf.buf[pfxlen-1] == '/')
		pfxlen -= 1;

	entlen = st_add(pfxlen, 43); /* '/' + 2 hex + '/' + 38 hex + NUL */
	ent = xmalloc(st_add(sizeof(*ent), entlen));
	memcpy(ent->base, pathbuf.buf, pfxlen);
	strbuf_release(&pathbuf);

	ent->name = ent->base + pfxlen + 1;
	ent->base[pfxlen + 3] = '/';
	ent->base[pfxlen] = ent->base[entlen-1] = 0;

	/* Detect cases where alternate disappeared */
	if (!is_directory(ent->base)) {
		error("object directory %s does not exist; "
		      "check .git/objects/info/alternates.",
		      ent->base);
		free(ent);
		return -1;
	}

	/* Prevent the common mistake of listing the same
	 * thing twice, or object directory itself.
	 */
	for (alt = alt_odb_list; alt; alt = alt->next) {
		if (pfxlen == alt->name - alt->base - 1 &&
		    !memcmp(ent->base, alt->base, pfxlen)) {
			free(ent);
			return -1;
		}
	}
	if (!fspathcmp(ent->base, normalized_objdir)) {
		free(ent);
		return -1;
	}

	/* add the alternate entry */
	*alt_odb_tail = ent;
	alt_odb_tail = &(ent->next);
	ent->next = NULL;

	/* recursively add alternates */
	read_info_alternates(ent->base, depth + 1);

	ent->base[pfxlen] = '/';

	return 0;
}
