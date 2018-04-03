			}
			die("Not a git repository (or any of the parent directories): %s", DEFAULT_GIT_DIR_ENVIRONMENT);
		}
		if (one_filesystem) {
			if (stat("..", &buf)) {
				cwd[offset] = '\0';
				die_errno("failed to stat '%s/..'", cwd);
			}
			if (buf.st_dev != current_device) {
				if (nongit_ok) {
					if (chdir(cwd))
						die_errno("Cannot come back to cwd");
					*nongit_ok = 1;
					return NULL;
				}
				cwd[offset] = '\0';
				die("Not a git repository (or any parent up to mount parent %s)\n"
					"Stopping at filesystem boundary since GIT_ONE_FILESYSTEM is set.", cwd);
			}
		}
		if (chdir("..")) {
			cwd[offset] = '\0';
			die_errno("Cannot change to '%s/..'", cwd);