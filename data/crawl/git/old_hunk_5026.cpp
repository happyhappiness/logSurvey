
	t = init_notes_check("remove");

	fprintf(stderr, "Removing note for object %s\n", sha1_to_hex(object));
	remove_note(t, object);

	commit_notes(t, "Notes removed by 'git notes remove'");
	free_notes(t);
	return 0;
}

static int prune(int argc, const char **argv, const char *prefix)
