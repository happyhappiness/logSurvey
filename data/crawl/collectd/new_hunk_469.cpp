	 * Change directory. We do this _after_ reading the config and loading
	 * modules to relative paths work as expected.
	 */
	if ((datadir = global_option_get ("BaseDir")) != NULL)
	{
		fprintf (stderr, "Don't have a datadir to use. This should not happen. Ever.");
		return (1);
