	while (refspec_nr--)
		argv[argc++] = *refspec++;
	argv[argc] = NULL;
	return !!run_command_v_opt(argv, RUN_GIT_CMD);
}

static struct ref *get_refs_via_curl(struct transport *transport, int for_push)