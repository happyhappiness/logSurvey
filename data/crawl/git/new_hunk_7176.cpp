	 */

	if (last_dot == NULL) {
		error("key does not contain a section: %s", key);
		ret = 2;
		goto out_free;
	}
