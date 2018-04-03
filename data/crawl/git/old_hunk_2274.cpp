		die(_("unrecognized color: %%(color:%s)"), color_value);
}

static align_type parse_align_position(const char *s)
{
	if (!strcmp(s, "right"))
