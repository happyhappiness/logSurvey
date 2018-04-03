
		printf(" * [%s] %s\n", dry_run ? "would prune" : "pruned",
		       abbrev_ref(refname, "refs/remotes/"));
		warn_dangling_symref(stdout, dangling_msg, refname);
	}

	free_remote_ref_states(&states);
