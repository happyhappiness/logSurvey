		if (offset <= ceil_offset)
			return setup_nongit(cwd, nongit_ok);
		if (one_filesystem) {
			if (stat("..", &buf)) {
				cwd[offset] = '\0';
				die_errno("failed to stat '%s/..'", cwd);
			}
			if (buf.st_dev != current_device) {
				if (nongit_ok) {
					if (chdir(cwd))
						die_errno("Cannot come back to cwd");