	   "\n"
	   "    git push %s HEAD:<name-of-remote-branch>\n");

static void setup_push_upstream(struct remote *remote, struct branch *branch,
				int triangular)
{
	struct strbuf refspec = STRBUF_INIT;

	if (!branch)
		die(_(message_detached_head_die), remote->name);
	if (!branch->merge_nr || !branch->merge || !branch->remote_name)
