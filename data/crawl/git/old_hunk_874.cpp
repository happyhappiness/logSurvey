	printf("summary %s\n", ci.summary.buf);
	if (suspect->commit->object.flags & UNINTERESTING)
		printf("boundary\n");
	if (suspect->previous) {
		struct origin *prev = suspect->previous;
		printf("previous %s ", oid_to_hex(&prev->commit->object.oid));
		write_name_quoted(prev->path, stdout, '\n');
	}

	commit_info_destroy(&ci);
