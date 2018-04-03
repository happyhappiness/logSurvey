			if (valid == todo_list->items[i].command)
				continue;
			else if (valid == TODO_PICK)
				return error(_("Cannot cherry-pick during a revert."));
			else
				return error(_("Cannot revert during a cherry-pick."));
	}

	return 0;
