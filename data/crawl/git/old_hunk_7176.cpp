	 */

	if (last_dot == NULL) {
		fprintf(stderr, "key does not contain a section: %s\n", key);
		ret = 2;
		goto out_free;
	}
