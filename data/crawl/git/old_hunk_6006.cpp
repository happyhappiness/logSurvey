	return 0;
}

int cmd_replace(int argc, const char **argv, const char *prefix)
{
	int list = 0, delete = 0;
	struct option options[] = {
		OPT_BOOLEAN('l', NULL, &list, "list replace refs"),
		OPT_BOOLEAN('d', NULL, &delete, "delete replace refs"),
		OPT_END()
	};

