				continue;
			}
			if (!strcmp(arg, "--resolve-git-dir")) {
				const char *gitdir = resolve_gitdir(argv[i+1]);
				if (!gitdir)
					die("not a gitdir '%s'", argv[i+1]);
				puts(gitdir);
				continue;
			}