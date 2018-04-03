	}
}

static int do_push(const char *repo, int flags)
{
	int i, errs;
	struct remote *remote = remote_get(repo);

	if (!remote)
		die("bad repository '%s'", repo);

	if (!refspec && !all && remote->push_refspec_nr) {
		refspec = remote->push_refspec;
		refspec_nr = remote->push_refspec_nr;
	}
	errs = 0;
	for (i = 0; i < remote->uri_nr; i++) {
		struct transport *transport =
			transport_get(remote, remote->uri[i], 0);
		int err;
		if (receivepack)
			transport_set_option(transport,
					     TRANS_OPT_RECEIVEPACK, receivepack);
		if (thin)
			transport_set_option(transport, TRANS_OPT_THIN, "yes");

		if (verbose)
			fprintf(stderr, "Pushing to %s\n", remote->uri[i]);
		err = transport_push(transport, refspec_nr, refspec, flags);
		err |= transport_disconnect(transport);

		if (!err)
			continue;

		error("failed to push to '%s'", remote->uri[i]);
		errs++;
	}
	return !!errs;
