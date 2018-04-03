			argp = stdin_only;
	}

	ret = split_mbox(argp, dir, allow_bare, nr_prec, nr);
	if (ret != -1)
		printf("%d\n", ret);

	return ret == -1;
}
