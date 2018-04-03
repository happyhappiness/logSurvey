		if (errno == EACCES)
			return error("insufficient permission for adding an object to repository database %s", get_object_directory());
		else
			return error_errno("unable to create temporary file");
	}

	/* Set it up */
