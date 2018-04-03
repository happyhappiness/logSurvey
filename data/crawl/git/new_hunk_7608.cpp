		if (S_ISDIR(st.st_mode)) {
			strbuf_addstr(&directory, ent->name);
			if (show_only && (remove_directories || matches)) {
				printf("Would remove %s\n",
				       directory.buf + prefix_offset);
			} else if (quiet && (remove_directories || matches)) {
				remove_dir_recursively(&directory, 0);
			} else if (remove_directories || matches) {
				printf("Removing %s\n",
				       directory.buf + prefix_offset);
				remove_dir_recursively(&directory, 0);
			} else if (show_only) {
				printf("Would not remove %s\n",
				       directory.buf + prefix_offset);
			} else {
				printf("Not removing %s\n",
				       directory.buf + prefix_offset);
			}
			strbuf_reset(&directory);
		} else {
			if (pathspec && !matches)
				continue;
			if (show_only) {
				printf("Would remove %s\n",
				       ent->name + prefix_offset);
				continue;
			} else if (!quiet) {
				printf("Removing %s\n",
				       ent->name + prefix_offset);
			}
			unlink(ent->name);
		}