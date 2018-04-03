	discard_index(&result);

	 if (res)
		 return error(_("could not write temporary index to %s"),
			      state->fake_ancestor);

	 return 0;