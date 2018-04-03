			qname = quote_path_relative(directory.buf, directory.len, &buf, prefix);
			if (show_only && (remove_directories ||
			    (matches == MATCHED_EXACTLY))) {
				printf(_("Would remove %s\n"), qname);
			} else if (remove_directories ||
				   (matches == MATCHED_EXACTLY)) {
				if (!quiet)
					printf(_("Removing %s\n"), qname);
				if (remove_dir_recursively(&directory,
							   rm_flags) != 0) {
					warning(_("failed to remove %s"), qname);
					errors++;
				}
			} else if (show_only) {
				printf(_("Would not remove %s\n"), qname);
			} else {
				printf(_("Not removing %s\n"), qname);
			}
			strbuf_reset(&directory);
		} else {
			if (pathspec && !matches)
				continue;
			qname = quote_path_relative(ent->name, -1, &buf, prefix);
			if (show_only) {
				printf(_("Would remove %s\n"), qname);
				continue;
			} else if (!quiet) {
				printf(_("Removing %s\n"), qname);
			}
			if (unlink(ent->name) != 0) {
				warning(_("failed to remove %s"), qname);
				errors++;
			}
		}
