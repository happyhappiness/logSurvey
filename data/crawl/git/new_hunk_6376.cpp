	}
}

static void setup_push_tracking(void)
{
	struct strbuf refspec = STRBUF_INIT;
	struct branch *branch = branch_get(NULL);
	if (!branch)
		die("You are not currently on a branch.");
	if (!branch->merge_nr)
		die("The current branch %s is not tracking anything.",
		    branch->name);
	if (branch->merge_nr != 1)
		die("The current branch %s is tracking multiple branches, "
		    "refusing to push.", branch->name);
	strbuf_addf(&refspec, "%s:%s", branch->name, branch->merge[0]->src);
	add_refspec(refspec.buf);
}

static void setup_default_push_refspecs(void)
{
	git_config(git_default_config, NULL);
	switch (push_default) {
	case PUSH_DEFAULT_UNSPECIFIED:
		/* fallthrough */

	case PUSH_DEFAULT_MATCHING:
		add_refspec(":");
		break;

	case PUSH_DEFAULT_TRACKING:
		setup_push_tracking();
		break;

	case PUSH_DEFAULT_CURRENT:
		add_refspec("HEAD");
		break;

	case PUSH_DEFAULT_NOTHING:
		die("You didn't specify any refspecs to push, and "
		    "push.default is \"nothing\".");
		break;
	}
}

static int do_push(const char *repo, int flags)
{
	int i, errs;
