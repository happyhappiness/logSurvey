	fill_filespec(one, sha1, mode);
	diff_queue(&diff_queued_diff, one, two)->is_unmerged = 1;
}

static char *run_textconv(const char *pgm, struct diff_filespec *spec,
		size_t *outsize)
{
	struct diff_tempfile temp;
	const char *argv[3];
	const char **arg = argv;
	struct child_process child;
	struct strbuf buf = STRBUF_INIT;

	prepare_temp_file(spec->path, &temp, spec);
	*arg++ = pgm;
	*arg++ = temp.name;
	*arg = NULL;

	memset(&child, 0, sizeof(child));
	child.argv = argv;
	child.out = -1;
	if (start_command(&child) != 0 ||
	    strbuf_read(&buf, child.out, 0) < 0 ||
	    finish_command(&child) != 0) {
		if (temp.name == temp.tmp_path)
			unlink(temp.name);
		error("error running textconv command '%s'", pgm);
		return NULL;
	}
	if (temp.name == temp.tmp_path)
		unlink(temp.name);

	return strbuf_detach(&buf, outsize);
}
