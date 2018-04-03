static void regenerate_marks(void)
{
	int ret;
	FILE *marksfile = xfopen(marksfilename, "w+");

	ret = for_each_note(NULL, 0, note2mark_cb, marksfile);
	if (ret)
		die("Regeneration of marks failed, returned %d.", ret);
