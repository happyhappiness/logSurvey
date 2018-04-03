		die("Branch rename failed");
	strbuf_release(&logmsg);

	/* no need to pass logmsg here as HEAD didn't really move */
	if (!strcmp(oldname, head) && create_symref("HEAD", newref.buf, NULL))
		die("Branch renamed to %s, but HEAD is not updated!", newname);
