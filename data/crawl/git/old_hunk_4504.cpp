	struct strbuf refspec = STRBUF_INIT;
	struct branch *branch = branch_get(NULL);
	if (!branch)
		die("You are not currently on a branch.");
	if (!branch->merge_nr || !branch->merge)
		die("The current branch %s is not tracking anything.",
		    branch->name);
	if (branch->merge_nr != 1)
		die("The current branch %s is tracking multiple branches, "
		    "refusing to push.", branch->name);
	strbuf_addf(&refspec, "%s:%s", branch->name, branch->merge[0]->src);
	add_refspec(refspec.buf);
}
