{
	const char *c = color(WT_STATUS_HEADER, s);

	status_printf_ln(s, c, "Changes to be committed:");
	if (!advice_status_hints)
		return;
	if (s->in_merge)