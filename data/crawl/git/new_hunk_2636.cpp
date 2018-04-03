	}

	strbuf_addstr(&msg, "\n\n");
	strbuf_addbuf(&msg, &mi.log_message);
	stripspace(&msg, 0);

	if (state->signoff)
