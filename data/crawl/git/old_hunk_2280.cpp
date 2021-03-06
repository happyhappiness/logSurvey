			refname = branch_get_push(branch, NULL);
			if (!refname)
				continue;
		} else if (match_atom_name(name, "color", &valp)) {
			char color[COLOR_MAXLEN] = "";

			if (!valp)
				die(_("expected format: %%(color:<color>)"));
			if (color_parse(valp, color) < 0)
				die(_("unable to parse format"));
			v->s = xstrdup(color);
			continue;
		} else if (!strcmp(name, "flag")) {
			char buf[256], *cp = buf;