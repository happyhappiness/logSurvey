
			printf(" * [%s] %s\n", dry_run ? "would prune" : "pruned",
			       abbrev_ref(refname, "refs/remotes/"));
		}

		/* NEEDSWORK: free remote */
