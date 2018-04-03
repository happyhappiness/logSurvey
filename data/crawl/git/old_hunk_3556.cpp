		}

		if (S_ISDIR(st.st_mode)) {
			strbuf_addstr(&directory, ent->name);
			if (remove_directories || (matches == MATCHED_EXACTLY)) {
				if (remove_dirs(&directory, prefix, rm_flags, dry_run, quiet, &gone))
					errors++;
				if (gone && !quiet) {
					qname = quote_path_relative(directory.buf, prefix, &buf);
					printf(dry_run ? _(msg_would_remove) : _(msg_remove), qname);
				}
			}
			strbuf_reset(&directory);
		} else {
			if (pathspec && !matches)
				continue;
			res = dry_run ? 0 : unlink(ent->name);
			if (res) {
				qname = quote_path_relative(ent->name, prefix, &buf);
				warning(_(msg_warn_remove_failed), qname);
				errors++;
			} else if (!quiet) {
				qname = quote_path_relative(ent->name, prefix, &buf);
				printf(dry_run ? _(msg_would_remove) : _(msg_remove), qname);
			}
		}
	}
	free(seen);

	strbuf_release(&directory);
	string_list_clear(&exclude_list, 0);
	return (errors != 0);
}