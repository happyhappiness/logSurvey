		else if (!is_noop(item->command))
			fixup_okay = 1;
	}
	if (!todo_list->nr)
		return error(_("no commits parsed."));
	return res;
}

