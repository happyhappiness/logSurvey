
	buf = packet_read_line(fd[0], NULL);
	if (!buf)
		die(_("git archive: expected ACK/NAK, got a flush packet"));
	if (strcmp(buf, "ACK")) {
		if (starts_with(buf, "NACK "))
			die(_("git archive: NACK %s"), buf + 5);
