			const char *v = skip_prefix(arg, "--decorate=");
			decoration_style = parse_decoration_style(arg, v);
			if (decoration_style < 0)
				die(_("invalid --decorate option: %s"), arg);
			decoration_given = 1;
		} else if (!strcmp(arg, "--no-decorate")) {
			decoration_style = 0;
