		warning("Reflog action message too long: %.*s...", 50, buf);
}

int cmd_reset(int argc, const char **argv, const char *prefix)
{
	int i = 0, reset_type = NONE, update_ref_status = 0, quiet = 0;
