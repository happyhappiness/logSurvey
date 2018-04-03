			committer = git_committer_info(IDENT_ERROR_ON_NO_NAME);
			endpos = strchr(committer, '>');
			if (!endpos)
				die("bogus committer info %s\n", committer);
			add_signoff = xmemdupz(committer, endpos - committer + 1);
		}
		else if (!strcmp(argv[i], "--attach")) {
