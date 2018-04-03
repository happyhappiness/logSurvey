
	if (patchbreak(line)) {
		if (mi->message_id)
			fprintf(mi->cmitmsg, "Message-Id: %s\n", mi->message_id);
		fclose(mi->cmitmsg);
		mi->cmitmsg = NULL;
		return 1;
	}

	fputs(line->buf, mi->cmitmsg);
	return 0;
}

