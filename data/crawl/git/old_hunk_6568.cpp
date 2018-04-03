				*nongit_ok = 1;
				return NULL;
			}
			die("Not a git repository");
		}
		if (chdir(".."))
			die("Cannot change to %s/..: %s", cwd, strerror(errno));