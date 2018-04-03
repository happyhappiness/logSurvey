			transport_set_option(transport, TRANS_OPT_THIN, "yes");

		if (flags & TRANSPORT_PUSH_VERBOSE)
			fprintf(stderr, "Pushing to %s\n", url[i]);
		err = transport_push(transport, refspec_nr, refspec, flags);
		err |= transport_disconnect(transport);

		if (!err)
			continue;

		error("failed to push some refs to '%s'", url[i]);
		errs++;
	}
	return !!errs;
