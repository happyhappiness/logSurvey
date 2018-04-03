	uint32_t mark;
	struct object_decoration *deco = idnums.hash;
	FILE *f;

	f = fopen(file, "w");
	if (!f)
		error("Unable to open marks file %s for writing", file);

	for (i = 0; i < idnums.size; i++) {
		if (deco->base && deco->base->type == 1) {
			mark = ptr_to_mark(deco->decoration);
			fprintf(f, ":%"PRIu32" %s\n", mark,
				sha1_to_hex(deco->base->sha1));
		}
		deco++;
	}

	if (ferror(f) || fclose(f))
		error("Unable to write marks file %s.", file);
}
