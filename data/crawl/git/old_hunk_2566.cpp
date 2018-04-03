		die("Could not parse commit from NOTES_MERGE_PARTIAL.");

	if (partial->parents)
		hashcpy(parent_sha1, partial->parents->item->object.sha1);
	else
		hashclr(parent_sha1);

