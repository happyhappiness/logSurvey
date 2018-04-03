			fake_av[1] = NULL;
			av = fake_av;
			ac = 1;
		}
		if (ac != 1)
			die("--reflog option needs one branch name");