		strbuf_release(&buf);
	} else if (argc > 0 && argc <= 2) {
		struct branch *branch = branch_get(argv[0]);
		int branch_existed = 0, remote_tracking = 0;
		struct strbuf buf = STRBUF_INIT;

		if (!strcmp(argv[0], "HEAD"))
			die(_("it does not make sense to create 'HEAD' manually"));
