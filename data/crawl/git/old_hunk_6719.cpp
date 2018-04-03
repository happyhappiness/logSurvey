	 * make it another option?  For now suppress them.
	 */
	if (opt->count && count)
		printf("%s:%u\n", name, count);
	return !!last_hit;
}

