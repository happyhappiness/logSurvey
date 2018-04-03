		die(_("unrecognized %%(contents) argument: %s"), arg);
}

static align_type parse_align_position(const char *s)
{
	if (!strcmp(s, "right"))
