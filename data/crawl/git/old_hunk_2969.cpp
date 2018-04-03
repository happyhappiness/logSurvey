	const char *argv_gc_auto[] = {"gc", "--auto", NULL};
	struct strbuf sb = STRBUF_INIT;

	refresh_and_write_cache();

	if (index_has_changes(&sb))
		die(_("Dirty index: cannot apply patches (dirty: %s)"), sb.buf);

	strbuf_release(&sb);

