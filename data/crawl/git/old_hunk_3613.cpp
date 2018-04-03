			continue;

		if (!submodule_uses_gitfile(name))
			errs = error(_("submodule '%s' (or one of its nested "
				     "submodules) uses a .git directory\n"
				     "(use 'rm -rf' if you really want to remove "
				     "it including all of its history)"), name);
	}

	return errs;
}
