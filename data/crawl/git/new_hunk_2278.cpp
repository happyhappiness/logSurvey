			else
				v->s = " ";
			continue;
		} else if (starts_with(name, "align")) {
			v->u.align = atom->u.align;
			v->handler = align_atom_handler;
			continue;
		} else if (!strcmp(name, "end")) {