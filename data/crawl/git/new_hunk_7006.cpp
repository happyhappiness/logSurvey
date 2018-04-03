	return !stat(rr_path(name, "postimage"), &st);
}

static void unlink_rr_item(const char *name)
{
	unlink(rr_path(name, "thisimage"));
