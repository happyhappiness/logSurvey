		if (offset <= ceil_offset) {
			if (nongit_ok) {
				if (chdir(cwd))
					die("Cannot come back to cwd");
				*nongit_ok = 1;
				return NULL;
			}
