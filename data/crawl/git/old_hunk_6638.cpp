	}
}

void show_decorations(struct commit *commit)
{
	const char *prefix;
	struct name_decoration *decoration;

	decoration = lookup_decoration(&name_decoration, &commit->object);
	if (!decoration)
		return;
