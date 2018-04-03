			   REF_NODEREF, DIE_ON_ERR);
		if (!opts->quiet) {
			if (old->path)
				fprintf(stderr, "Note: moving to \"%s\" which isn't a local branch\nIf you want to create a new branch from this checkout, you may do so\n(now or later) by using -b with the checkout command again. Example:\n  git checkout -b <new_branch_name>\n", new->name);
			describe_detached_head("HEAD is now at", new->commit);
		}
	}
