			i++;
			if (i == argc)
				die("option -m needs an argument.");
			message = xstrdup(argv[i]);
			continue;
		}
