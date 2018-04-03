			continue;
		} else if (match_atom_name(name, "align", &valp)) {
			struct align *align = &v->u.align;
			struct string_list params = STRING_LIST_INIT_DUP;
			int i;
			int width = -1;

			if (!valp)
				die(_("expected format: %%(align:<width>,<position>)"));

			align->position = ALIGN_LEFT;

			string_list_split(&params, valp, ',', -1);
			for (i = 0; i < params.nr; i++) {
				const char *s = params.items[i].string;
				if (!strtoul_ui(s, 10, (unsigned int *)&width))
					;
				else if (!strcmp(s, "left"))
					align->position = ALIGN_LEFT;
				else if (!strcmp(s, "right"))
					align->position = ALIGN_RIGHT;
				else if (!strcmp(s, "middle"))
					align->position = ALIGN_MIDDLE;
				else
					die(_("improper format entered align:%s"), s);
			}

			if (width < 0)
				die(_("positive width expected with the %%(align) atom"));
			align->width = width;
			string_list_clear(&params, 0);
			v->handler = align_atom_handler;
			continue;
		} else if (!strcmp(name, "end")) {