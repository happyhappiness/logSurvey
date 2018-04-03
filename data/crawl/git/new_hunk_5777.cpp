		hook.env = env;
	}

	ret = run_command(&hook);
	free(argv);
	return ret;
}
