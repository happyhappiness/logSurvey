	}

	if (patchbreak(line)) {
		if (message_id)
			fprintf(cmitmsg, "Message-Id: %s\n", message_id);
		fclose(cmitmsg);
		cmitmsg = NULL;
		return 1;
