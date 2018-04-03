static void die_initial_contact(int got_at_least_one_head)
{
	if (got_at_least_one_head)
		die(_("The remote end hung up upon initial contact"));
	else
		die(_("Could not read from remote repository.\n\n"
		      "Please make sure you have the correct access rights\n"
		      "and the repository exists."));
}

static void parse_one_symref_info(struct string_list *symref, const char *val, int len)
