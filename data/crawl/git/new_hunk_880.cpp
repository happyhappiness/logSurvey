	 */
	if (!index_only) {
		int removed = 0, gitmodules_modified = 0;
		for (i = 0; i < list.nr; i++) {
			const char *path = list.entry[i].name;
			if (list.entry[i].is_submodule) {
				struct strbuf buf = STRBUF_INIT;

				strbuf_addstr(&buf, path);
				if (remove_dir_recursively(&buf, 0))
					die(_("could not remove '%s'"), path);
				strbuf_release(&buf);

				removed = 1;
				if (!remove_path_from_gitmodules(path))
					gitmodules_modified = 1;
				continue;
			}
			if (!remove_path(path)) {
				removed = 1;
