		struct strbuf branch_ref = STRBUF_INIT;

		if (!argc) {
			if (detached)
				die(_("Cannot give description to detached HEAD"));
			branch_name = head;
		} else if (argc == 1)
