	for_each_note(t, 0, prune_notes_helper, &l);

	while (l) {
		remove_note(t, l->sha1);
		l = l->next;
	}
}
