			fake_av[1] = NULL;
			av = fake_av;
			ac = 1;
			if (!*av)
				die("no branches given, and HEAD is not valid");
		}
		if (ac != 1)
			die("--reflog option needs one branch name");