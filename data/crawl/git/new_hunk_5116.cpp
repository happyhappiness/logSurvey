			fprintf(stderr, " %.*s", 8,
				sha1_to_hex(pp->item->object.sha1));

		subject_len = find_commit_subject(buf, &subject_start);
		if (subject_len)
			fprintf(stderr, " %.*s", subject_len, subject_start);
		fprintf(stderr, "\n");
	}
}