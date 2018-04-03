		warning("Reflog action message too long: %.*s...", 50, buf);
}

static void die_if_unmerged_cache(int reset_type)
{
	if (is_merge() || read_cache() < 0 || unmerged_cache())
		die("Cannot do a %s reset in the middle of a merge.",
		    reset_type_names[reset_type]);

}

int cmd_reset(int argc, const char **argv, const char *prefix)
{
	int i = 0, reset_type = NONE, update_ref_status = 0, quiet = 0;
