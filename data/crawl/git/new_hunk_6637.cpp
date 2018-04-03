		if (!strcmp(arg, "--decorate")) {
			load_ref_decorations();
			decorate = 1;
		} else if (!strcmp(arg, "--source")) {
			rev->show_source = 1;
		} else
			die("unrecognized argument: %s", arg);
	}
