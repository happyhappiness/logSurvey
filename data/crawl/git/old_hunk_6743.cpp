	ent->base[pfxlen] = ent->base[entlen-1] = 0;

	/* Detect cases where alternate disappeared */
	if (stat(ent->base, &st) || !S_ISDIR(st.st_mode)) {
		error("object directory %s does not exist; "
		      "check .git/objects/info/alternates.",
		      ent->base);