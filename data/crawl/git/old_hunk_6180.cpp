	free(in_pack.array);
}

static void loosen_unused_packed_objects(struct rev_info *revs)
{
	struct packed_git *p;
	uint32_t i;
	const unsigned char *sha1;

	for (p = packed_git; p; p = p->next) {
		for (i = 0; i < revs->num_ignore_packed; i++) {
			if (matches_pack_name(p, revs->ignore_packed[i]))
				break;
		}
		if (revs->num_ignore_packed <= i)
			continue;

		if (open_pack_index(p))
			die("cannot open pack index");

		for (i = 0; i < p->num_objects; i++) {
			sha1 = nth_packed_object_sha1(p, i);
			if (!locate_object_entry(sha1))
				if (force_object_loose(sha1, p->mtime))
					die("unable to force loose object");
		}
