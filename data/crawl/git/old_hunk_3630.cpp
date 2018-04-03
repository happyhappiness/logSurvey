	    remote->name, branch->name, advice_maybe);
}

static void setup_push_upstream(struct remote *remote, int simple)
{
	struct strbuf refspec = STRBUF_INIT;
	struct branch *branch = branch_get(NULL);
	if (!branch)
		die(_("You are not currently on a branch.\n"
		    "To push the history leading to the current (detached HEAD)\n"
		    "state now, use\n"
		    "\n"
		    "    git push %s HEAD:<name-of-remote-branch>\n"),
		    remote->name);
	if (!branch->merge_nr || !branch->merge || !branch->remote_name)
		die(_("The current branch %s has no upstream branch.\n"
		    "To push the current branch and set the remote as upstream, use\n"