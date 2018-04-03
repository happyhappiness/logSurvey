				continue;
			}
			if (!strcmp(arg, "--resolve-git-dir")) {
				const char *gitdir = argv[++i];
				if (!gitdir)
					die("--resolve-git-dir requires an argument");
				gitdir = resolve_gitdir(gitdir);
				if (!gitdir)
					die("not a gitdir '%s'", argv[i]);
				puts(gitdir);
				continue;
			}