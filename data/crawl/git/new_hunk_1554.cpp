		new_name = patch->new_name;

	if (old_name && !verify_path(old_name))
		return error(_("invalid path '%s'"), old_name);
	if (new_name && !verify_path(new_name))
		return error(_("invalid path '%s'"), new_name);
	return 0;
}

/*
