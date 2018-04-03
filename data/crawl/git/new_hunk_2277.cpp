	return -1;
}

static void align_atom_parser(struct used_atom *atom, const char *arg)
{
	struct align *align = &atom->u.align;
	struct string_list params = STRING_LIST_INIT_DUP;
	int i;
	unsigned int width = ~0U;

	if (!arg)
		die(_("expected format: %%(align:<width>,<position>)"));

	align->position = ALIGN_LEFT;

	string_list_split(&params, arg, ',', -1);
	for (i = 0; i < params.nr; i++) {
		const char *s = params.items[i].string;
		int position;

		if (!strtoul_ui(s, 10, &width))
			;
		else if ((position = parse_align_position(s)) >= 0)
			align->position = position;
		else
			die(_("unrecognized %%(align) argument: %s"), s);
	}

	if (width == ~0U)
		die(_("positive width expected with the %%(align) atom"));
	align->width = width;
	string_list_clear(&params, 0);
}

static struct {
	const char *name;
	cmp_type cmp_type;
