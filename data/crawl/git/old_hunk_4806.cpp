	}
}

static void setup_push_upstream(void)
{
	struct strbuf refspec = STRBUF_INIT;
	struct branch *branch = branch_get(NULL);
	if (!branch)
		die("You are not currently on a branch.");
	if (!branch->merge_nr || !branch->merge)
		die("The current branch %s has no upstream branch.",
		    branch->name);
	if (branch->merge_nr != 1)
		die("The current branch %s has multiple upstream branches, "
