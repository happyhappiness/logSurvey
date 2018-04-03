	     frag;
	     cnt++, frag = frag->next) {
		if (!frag->rejected) {
			fprintf_ln(stderr, _("Hunk #%d applied cleanly."), cnt);
			continue;
		}
		fprintf_ln(stderr, _("Rejected hunk #%d."), cnt);
		fprintf(rej, "%.*s", frag->size, frag->patch);
		if (frag->patch[frag->size-1] != '\n')
			fputc('\n', rej);
