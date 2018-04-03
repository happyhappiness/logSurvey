	const char *argv_gc_auto[] = {"gc", "--auto", NULL};
	struct strbuf sb = STRBUF_INIT;

	unlink(am_path(state, "dirtyindex"));

	refresh_and_write_cache();

	if (index_has_changes(&sb)) {
		write_file(am_path(state, "dirtyindex"), 1, "t");
		die(_("Dirty index: cannot apply patches (dirty: %s)"), sb.buf);
	}

	strbuf_release(&sb);

