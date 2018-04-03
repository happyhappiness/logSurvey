		die(_("unrecognized format: %%(%s)"), atom->name);
}

static align_type parse_align_position(const char *s)
{
	if (!strcmp(s, "right"))
