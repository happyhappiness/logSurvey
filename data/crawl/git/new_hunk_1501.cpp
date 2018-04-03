	     frag;
	     cnt++, frag = frag->next) {
		if (!frag->rejected) {
			if (state->apply_verbosity > verbosity_silent)
				fprintf_ln(stderr, _("Hunk #%d applied cleanly."), cnt);
			continue;
		}
		if (state->apply_verbosity > verbosity_silent)
			fprintf_ln(stderr, _("Rejected hunk #%d."), cnt);
		fprintf(rej, "%.*s", frag->size, frag->patch);
		if (frag->patch[frag->size-1] != '\n')
			fputc('\n', rej);
