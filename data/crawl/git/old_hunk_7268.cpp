	index += 4 * 256;
	hi = ntohl(level1_ofs[*sha1]);
	lo = ((*sha1 == 0x0) ? 0 : ntohl(level1_ofs[*sha1 - 1]));

	do {
		unsigned mi = (lo + hi) / 2;
		unsigned x = (p->index_version > 1) ? (mi * 20) : (mi * 24 + 4);
		int cmp = hashcmp(index + x, sha1);
		if (!cmp)
			return nth_packed_object_offset(p, mi);
		if (cmp > 0)