	return commitable ? 0 : 1;
}

int cmd_status(int argc, const char **argv, const char *prefix)
{
	struct wt_status s;
