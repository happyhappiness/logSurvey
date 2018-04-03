	struct strbuf one = STRBUF_INIT, two = STRBUF_INIT;
	FILE *f = fopen(path, "r");
	FILE *out = NULL;

	if (!f)
		return error("Could not open %s", path);
