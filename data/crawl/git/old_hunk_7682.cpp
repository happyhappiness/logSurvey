			 !strcmp(argv[i], "-s")) {
			const char *committer;
			const char *endpos;
			committer = git_committer_info(1);
			endpos = strchr(committer, '>');
			if (!endpos)
				die("bogos committer info %s\n", committer);
