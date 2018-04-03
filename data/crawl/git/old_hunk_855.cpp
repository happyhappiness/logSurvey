		if (parse_insn_line(item, p, eol)) {
			res = error(_("invalid line %d: %.*s"),
				i, (int)(eol - p), p);
			item->command = -1;
		}
	}
	if (!todo_list->nr)
		return error(_("no commits parsed."));
