	ent->base[pfxlen] = ent->base[entlen-1] = 0;

	/* Detect cases where alternate disappeared */
	if (!is_directory(ent->base)) {
		error("object directory %s does not exist; "
		      "check .git/objects/info/alternates.",
		      ent->base);