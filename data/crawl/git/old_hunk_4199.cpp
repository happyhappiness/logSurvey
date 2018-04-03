	return !open_packed_git(p);
}

static int find_pack_entry(const unsigned char *sha1, struct pack_entry *e)
{
	static struct packed_git *last_found = (void *)1;
	struct packed_git *p;
	off_t offset;

	prepare_packed_git();
	if (!packed_git)
		return 0;
	p = (last_found == (void *)1) ? packed_git : last_found;

	do {
		if (p->num_bad_objects) {
			unsigned i;
			for (i = 0; i < p->num_bad_objects; i++)
				if (!hashcmp(sha1, p->bad_object_sha1 + 20 * i))
					goto next;
		}

		offset = find_pack_entry_one(sha1, p);
		if (offset) {
			/*
			 * We are about to tell the caller where they can
			 * locate the requested object.  We better make
			 * sure the packfile is still here and can be
			 * accessed before supplying that answer, as
			 * it may have been deleted since the index
			 * was loaded!
			 */
			if (!is_pack_valid(p)) {
				warning("packfile %s cannot be accessed", p->pack_name);
				goto next;
			}
			e->offset = offset;
			e->p = p;
			hashcpy(e->sha1, sha1);
			last_found = p;
			return 1;
		}

		next:
		if (p == last_found)
			p = packed_git;
		else