	expand_refspecs();
}

static int do_push(const char *repo)
{
	int i, errs;
	int common_argc;
	const char **argv;
	int argc;
	struct remote *remote = remote_get(repo);

	if (!remote)
		die("bad repository '%s'", repo);

	if (remote->receivepack) {
		char *rp = xmalloc(strlen(remote->receivepack) + 16);
		sprintf(rp, "--receive-pack=%s", remote->receivepack);
		receivepack = rp;
	}
	if (!refspec && !all && !tags && remote->push_refspec_nr) {
		for (i = 0; i < remote->push_refspec_nr; i++) {
			if (!wildcard_ref(remote->push_refspec[i]))
				add_refspec(remote->push_refspec[i]);
		}
	}

	argv = xmalloc((refspec_nr + 10) * sizeof(char *));
	argv[0] = "dummy-send-pack";
	argc = 1;
