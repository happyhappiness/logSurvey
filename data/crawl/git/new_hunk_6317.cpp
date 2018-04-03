		/* FIXME!!! Collision check here ? */
	}

	if (adjust_shared_perm(filename))
		return error("unable to set permission to '%s'", filename);
	return 0;
}

