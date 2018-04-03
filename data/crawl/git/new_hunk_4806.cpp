	}
}

static void setup_push_upstream(struct remote *remote)
{
	struct strbuf refspec = STRBUF_INIT;
	struct branch *branch = branch_get(NULL);
	if (!branch)
		die("You are not currently on a branch.\n"
		    "To push the history leading to the current (detached HEAD)\n"
		    "state now, use\n"
		    "\n"
		    "    git push %s HEAD:<name-of-remote-branch>\n",
		    remote->name);
	if (!branch->merge_nr || !branch->merge)
		die("The current branch %s has no upstream branch.\n"
		    "To push the current branch and set the remote as upstream, use\n"
		    "\n"
		    "    git push --set-upstream %s %s\n",
		    branch->name,
		    remote->name,
		    branch->name);
	if (branch->merge_nr != 1)
		die("The current branch %s has multiple upstream branches, "
