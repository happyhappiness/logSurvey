	}
}

static void export_marks(char *file)
{
	unsigned int i;
	uint32_t mark;
	struct object_decoration *deco = idnums.hash;
	FILE *f;

	f = fopen(file, "w");
	if (!f)
		error("Unable to open marks file %s for writing", file);

	for (i = 0; i < idnums.size; ++i) {
		deco++;
		if (deco && deco->base && deco->base->type == 1) {
			mark = ptr_to_mark(deco->decoration);
			fprintf(f, ":%u %s\n", mark, sha1_to_hex(deco->base->sha1));
		}
	}

	if (ferror(f) || fclose(f))
		error("Unable to write marks file %s.", file);
}

static void import_marks(char * input_file)
{
	char line[512];
	FILE *f = fopen(input_file, "r");
	if (!f)
		die("cannot read %s: %s", input_file, strerror(errno));

	while (fgets(line, sizeof(line), f)) {
		uint32_t mark;
		char *line_end, *mark_end;
		unsigned char sha1[20];
		struct object *object;

		line_end = strchr(line, '\n');
		if (line[0] != ':' || !line_end)
			die("corrupt mark line: %s", line);
		*line_end = 0;

		mark = strtoumax(line + 1, &mark_end, 10);
		if (!mark || mark_end == line + 1
			|| *mark_end != ' ' || get_sha1(mark_end + 1, sha1))
			die("corrupt mark line: %s", line);

		object = parse_object(sha1);
		if (!object)
			die ("Could not read blob %s", sha1_to_hex(sha1));

		if (object->flags & SHOWN)
			error("Object %s already has a mark", sha1);

		mark_object(object, mark);
		if (last_idnum < mark)
			last_idnum = mark;

		object->flags |= SHOWN;
	}
	fclose(f);
}

int cmd_fast_export(int argc, const char **argv, const char *prefix)
{
	struct rev_info revs;
	struct object_array commits = { 0, 0, NULL };
	struct path_list extra_refs = { NULL, 0, 0, 0 };
	struct commit *commit;
	char *export_filename = NULL, *import_filename = NULL;
	struct option options[] = {
		OPT_INTEGER(0, "progress", &progress,
			    "show progress after <n> objects"),
		OPT_CALLBACK(0, "signed-tags", &signed_tag_mode, "mode",
			     "select handling of signed tags",
			     parse_opt_signed_tag_mode),
		OPT_STRING(0, "export-marks", &export_filename, "FILE",
			     "Dump marks to this file"),
		OPT_STRING(0, "import-marks", &import_filename, "FILE",
			     "Import marks from this file"),
		OPT_END()
	};

