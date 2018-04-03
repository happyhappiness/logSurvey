	for (i = 0; i < idnums.size; i++) {
		if (deco->base && deco->base->type == 1) {
			mark = ptr_to_mark(deco->decoration);
			fprintf(f, ":%u %s\n", mark, sha1_to_hex(deco->base->sha1));
		}
		deco++;
	}