static void body_atom_parser(struct used_atom *atom, const char *arg)
{
	if (arg)
		die("%%(body) does not take arguments");
	atom->u.contents.option = C_BODY_DEP;
}

static void subject_atom_parser(struct used_atom *atom, const char *arg)
{
	if (arg)
		die("%%(subject) does not take arguments");
	atom->u.contents.option = C_SUB;
}

