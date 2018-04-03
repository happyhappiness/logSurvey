		s->path,
		DIFF_FILE_VALID(s) ? "valid" : "invalid",
		s->mode,
		s->oid_valid ? oid_to_hex(&s->oid) : "");
	fprintf(stderr, "queue[%d] %s size %lu\n",
		x, one ? one : "",
		s->size);
