		if (offset <= ceil_offset) {
			if (nongit_ok) {
				if (chdir(cwd))
					die_errno("Cannot come back to cwd");
				*nongit_ok = 1;
				return NULL;
			}
