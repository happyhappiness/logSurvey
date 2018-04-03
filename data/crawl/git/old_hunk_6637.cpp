		if (!strcmp(arg, "--decorate")) {
			load_ref_decorations();
			decorate = 1;
		} else
			die("unrecognized argument: %s", arg);
	}
