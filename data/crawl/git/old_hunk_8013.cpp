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
