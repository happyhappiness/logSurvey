			const char *refname = states.stale.items[i].util;

			if (!dry_run)
				result |= delete_ref(refname, NULL, 0);

			printf(" * [%s] %s\n", dry_run ? "would prune" : "pruned",
			       abbrev_ref(refname, "refs/remotes/"));
