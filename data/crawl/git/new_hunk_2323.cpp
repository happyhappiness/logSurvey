		return;

	fputs(tag, stdout);
	write_eolinfo(NULL, ent->name);
	write_name(ent->name);
}

