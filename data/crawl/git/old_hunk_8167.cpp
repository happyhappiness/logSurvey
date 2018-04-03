					     ent, ents);
	if (rev.diffopt.exit_with_status)
		result = rev.diffopt.has_changes;
	return result;
}
