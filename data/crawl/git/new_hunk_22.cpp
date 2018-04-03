		index += 4;
	}

	while (lo < hi) {
		unsigned mi = lo + (hi - lo) / 2;
		int cmp = hashcmp(index + mi * stride, sha1);

		if (!cmp)
			return nth_packed_object_offset(p, mi);
		if (cmp > 0)