		strbuf_reset(&d->buf);

		if (launch_editor(d->edit_path, &d->buf, NULL)) {
			die(_("Please supply the note contents using either -m or -F option"));
		}
		strbuf_stripspace(&d->buf, 1);
	}
