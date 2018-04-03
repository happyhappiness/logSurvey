	free(in_pack.array);
}

static int has_sha1_pack_kept_or_nonlocal(const unsigned char *sha1)
{
	static struct packed_git *last_found = (void *)1;
	struct packed_git *p;

	p = (last_found != (void *)1) ? last_found : packed_git;

	while (p) {
		if ((!p->pack_local || p->pack_keep) &&
			find_pack_entry_one(sha1, p)) {
			last_found = p;
			return 1;
		}
		if (p == last_found)
			p = packed_git;
		else
			p = p->next;
		if (p == last_found)
			p = p->next;
	}
	return 0;
}

static void loosen_unused_packed_objects(struct rev_info *revs)
{
	struct packed_git *p;
	uint32_t i;
	const unsigned char *sha1;

	for (p = packed_git; p; p = p->next) {
		if (!p->pack_local || p->pack_keep)
			continue;

		if (open_pack_index(p))
			die("cannot open pack index");

		for (i = 0; i < p->num_objects; i++) {
			sha1 = nth_packed_object_sha1(p, i);
			if (!locate_object_entry(sha1) &&
				!has_sha1_pack_kept_or_nonlocal(sha1))
				if (force_object_loose(sha1, p->mtime))
					die("unable to force loose object");
		}
