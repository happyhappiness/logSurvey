		new_name = patch->new_name;

	if (old_name && !verify_path(old_name))
		die(_("invalid path '%s'"), old_name);
	if (new_name && !verify_path(new_name))
		die(_("invalid path '%s'"), new_name);
}

/*
