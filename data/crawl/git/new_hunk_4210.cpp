	if (status && !gpg_output.len)
		strbuf_addstr(&gpg_output, "No signature\n");

	show_sig_lines(opt, status, gpg_output.buf);

 out:
	strbuf_release(&gpg_output);