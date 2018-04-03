	/* Verify tag-line */
	tag_line = strchr(type_line, '\n');
	if (!tag_line)
		return error("char" PD_FMT ": could not find next \"\\n\"", type_line - buffer);
	tag_line++;
	if (memcmp(tag_line, "tag ", 4) || tag_line[4] == '\n')
		return error("char" PD_FMT ": no \"tag \" found", tag_line - buffer);

	/* Get the actual type */
	typelen = tag_line - type_line - strlen("type \n");
	if (typelen >= sizeof(type))
		return error("char" PD_FMT ": type too long", type_line+5 - buffer);

	memcpy(type, type_line+5, typelen);
	type[typelen] = 0;
