		hashcpy(sha1, o->sha1);
	}
	else {
		/*
		 * At this point, the syntax look correct, so
		 * if we do not get the needed object, we should
		 * barf.
		 */
		o = peel_to_type(name, len, o, expected_type);
		if (o) {
			hashcpy(sha1, o->sha1);
			return 0;
		}
		return -1;
	}
	return 0;
}