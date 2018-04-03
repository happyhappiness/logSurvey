		transport = transport_get(remote, remote->url[0]);

		if (!transport->get_refs_list || !transport->fetch)
			die(_("Don't know how to clone %s"), transport->url);

		transport_set_option(transport, TRANS_OPT_KEEP, "yes");

