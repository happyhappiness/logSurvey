			 * because the new tree entry will never be correct.
			 */
			die("entry '%s' object %s is a %s but specified type was (%s)",
				path, sha1_to_hex(sha1), typename(obj_type), typename(mode_type));
		}
	}

