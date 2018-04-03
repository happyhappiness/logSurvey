		 * Otherwise, 'git fetch remote no-such-ref' would
		 * silently succeed without issuing an error.
		 */
		for (i = 0; i < sought.nr; i++)
			error("no such remote ref %s", sought.items[i].string);
		ret = 1;
	}
	while (ref) {
		printf("%s %s\n",
