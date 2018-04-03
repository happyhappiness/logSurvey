	 * key name separated by a dot, we have to know where the dot is.
	 */

	if (last_dot == NULL || last_dot == key) {
		error("key does not contain a section: %s", key);
		return -2;
	}

	if (!last_dot[1]) {
		error("key does not contain variable name: %s", key);
		return -2;
	}

	baselen = last_dot - key;
	if (baselen_)
		*baselen_ = baselen;
