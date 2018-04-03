	return 0;
}

struct commit_graft *read_graft_line(struct strbuf *line)
{
	/* The format is just "Commit Parent1 Parent2 ...\n" */
	int i;
	struct commit_graft *graft = NULL;
	const int entry_size = GIT_SHA1_HEXSZ + 1;

	strbuf_rtrim(line);
	if (!line->len || line->buf[0] == '#')
		return NULL;
	if ((line->len + 1) % entry_size)
		goto bad_graft_data;
	i = (line->len + 1) / entry_size - 1;
	graft = xmalloc(st_add(sizeof(*graft), st_mult(GIT_SHA1_RAWSZ, i)));
	graft->nr_parent = i;
	if (get_oid_hex(line->buf, &graft->oid))
		goto bad_graft_data;
	for (i = GIT_SHA1_HEXSZ; i < line->len; i += entry_size) {
		if (line->buf[i] != ' ')
			goto bad_graft_data;
		if (get_sha1_hex(line->buf + i + 1, graft->parent[i/entry_size].hash))
			goto bad_graft_data;
	}
	return graft;

bad_graft_data:
	error("bad graft data: %s", line->buf);
	free(graft);
	return NULL;
}
