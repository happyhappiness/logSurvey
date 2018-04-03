
		if (S_ISDIR(st.st_mode)) {
			strbuf_addstr(&directory, ent->name);
			if (remove_directories || (matches == MATCHED_EXACTLY)) {
				if (remove_dirs(&directory, prefix, rm_flags, dry_run, quiet, &gone))
					errors++;
				if (gone && !quiet) {
					qname = quote_path_relative(directory.buf, directory.len, &buf, prefix);
					printf(dry_run ? _(msg_would_remove) : _(msg_remove), qname);
				}
			}
			strbuf_reset(&directory);
		} else {
			if (pathspec && !matches)
				continue;
			res = dry_run ? 0 : unlink(ent->name);
			if (res) {
				qname = quote_path_relative(ent->name, -1, &buf, prefix);
				warning(_(msg_warn_remove_failed), qname);
				errors++;
			} else if (!quiet) {
				qname = quote_path_relative(ent->name, -1, &buf, prefix);
				printf(dry_run ? _(msg_would_remove) : _(msg_remove), qname);
			}
		}
	}