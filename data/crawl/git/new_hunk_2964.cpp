		commit_list_insert(lookup_commit(parent), &parents);
	} else {
		ptr = NULL;
		say(state, stderr, _("applying to an empty history"));
	}

	author = fmt_ident(state->author_name, state->author_email,