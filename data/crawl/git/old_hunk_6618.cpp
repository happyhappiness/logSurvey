/* This is called when no merge was necessary. */
static void finish_up_to_date(const char *msg)
{
	printf("%s%s\n", squash ? " (nothing to squash)" : "", msg);
	drop_save();
}

