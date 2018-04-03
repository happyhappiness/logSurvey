	}

	if (patchbreak(line)) {
		if (mi->message_id)
			fprintf(cmitmsg, "Message-Id: %s\n", mi->message_id);
		fclose(cmitmsg);
		cmitmsg = NULL;
		return 1;
