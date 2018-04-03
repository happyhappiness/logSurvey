	} while (++pos < active_nr);
	if (!found)
		die("git merge-index: %s not in the cache", path);

	if (run_command_v_opt(arguments, 0)) {
		if (one_shot)
			err++;
		else {
			if (!quiet)
				die("merge program failed");
			exit(1);
		}
	}
	return found;
}
