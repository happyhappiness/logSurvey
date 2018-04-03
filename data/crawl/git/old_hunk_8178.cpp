			}
			if (!strcmp(arg, "--show-cdup")) {
				const char *pfx = prefix;
				while (pfx) {
					pfx = strchr(pfx, '/');
					if (pfx) {
