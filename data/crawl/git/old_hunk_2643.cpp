
	if (patchbreak(line)) {
		if (mi->message_id)
			fprintf(cmitmsg, "Message-Id: %s\n", mi->message_id);
		fclose(cmitmsg);
		cmitmsg = NULL;
		return 1;
	}

	fputs(line->buf, cmitmsg);
	return 0;
}

static void handle_patch(struct mailinfo *mi, const struct strbuf *line)
{
	fwrite(line->buf, 1, line->len, patchfile);
	mi->patch_lines++;
}

