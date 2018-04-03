	return (refs ? 0 : -1);
}

static int git_transport_push(struct transport *transport, int refspec_nr, const char **refspec, int flags)
{
	struct git_transport_data *data = transport->data;
	struct send_pack_args args;

	args.receivepack = data->receivepack;
	args.send_all = !!(flags & TRANSPORT_PUSH_ALL);
	args.send_mirror = !!(flags & TRANSPORT_PUSH_MIRROR);
	args.force_update = !!(flags & TRANSPORT_PUSH_FORCE);
	args.use_thin_pack = data->thin;
	args.verbose = !!(flags & TRANSPORT_PUSH_VERBOSE);
	args.dry_run = !!(flags & TRANSPORT_PUSH_DRY_RUN);

	return send_pack(&args, transport->url, transport->remote, refspec_nr, refspec);
}

static int disconnect_git(struct transport *transport)
