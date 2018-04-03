					printf("Removing %s\n", qname);
				if (remove_dir_recursively(&directory,
							   rm_flags) != 0) {
					warning("failed to remove %s", qname);
					errors++;
				}
			} else if (show_only) {
