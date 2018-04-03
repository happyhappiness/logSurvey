		git_config_set(key.buf, "true");
	}

	if (flag & BRANCH_CONFIG_VERBOSE)
		printf("Branch %s set up to track %s branch %s %s.\n",
		       local,
		       origin ? "remote" : "local",
		       remote,
		       rebasing ? "by rebasing" : "by merging");
	strbuf_release(&key);
}
