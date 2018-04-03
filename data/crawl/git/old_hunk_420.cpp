static void regenerate_marks(void)
{
	int ret;
	FILE *marksfile = fopen(marksfilename, "w+");

	if (!marksfile)
		die_errno("Couldn't create mark file %s.", marksfilename);
	ret = for_each_note(NULL, 0, note2mark_cb, marksfile);
	if (ret)
		die("Regeneration of marks failed, returned %d.", ret);
