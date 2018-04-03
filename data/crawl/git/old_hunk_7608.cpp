		if (S_ISDIR(st.st_mode)) {
			strbuf_addstr(&directory, ent->name);
			if (show_only && (remove_directories || matches)) {
				printf("Would remove %s\n", directory.buf);
			} else if (quiet && (remove_directories || matches)) {
				remove_dir_recursively(&directory, 0);
			} else if (remove_directories || matches) {
				printf("Removing %s\n", directory.buf);
				remove_dir_recursively(&directory, 0);
			} else if (show_only) {
				printf("Would not remove %s\n", directory.buf);
			} else {
				printf("Not removing %s\n", directory.buf);
			}
			strbuf_reset(&directory);
		} else {
			if (pathspec && !matches)
				continue;
			if (show_only) {
				printf("Would remove %s\n", ent->name);
				continue;
			} else if (!quiet) {
				printf("Removing %s\n", ent->name);
			}
			unlink(ent->name);
		}