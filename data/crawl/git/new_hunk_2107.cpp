			die(_("Failed to register url for submodule path '%s'"),
			    displaypath);
		if (!quiet)
			fprintf(stderr,
				_("Submodule '%s' (%s) registered for path '%s'\n"),
				sub->name, url, displaypath);
	}

