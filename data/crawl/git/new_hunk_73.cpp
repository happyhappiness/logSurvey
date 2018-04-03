				*envchanged = 1;
		} else if (!strcmp(cmd, "-C")) {
			if (*argc < 2) {
				fprintf(stderr, _("no directory given for -C\n" ));
				usage(git_usage_string);
			}
			if ((*argv)[1][0]) {
				if (chdir((*argv)[1]))
					die_errno("cannot change to '%s'", (*argv)[1]);
				if (envchanged)
					*envchanged = 1;
			}
