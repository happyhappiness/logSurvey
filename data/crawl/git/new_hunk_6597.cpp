			}
			die("Not a git repository");
		}
		if (chdir(".."))
			die("Cannot change to %s/..: %s", cwd, strerror(errno));
	}

	inside_git_dir = 0;