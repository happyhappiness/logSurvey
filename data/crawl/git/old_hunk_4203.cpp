			die_errno("unable to relay credential");
	}

	if (!send_request(socket, &buf))
		return;
	if (flags & FLAG_SPAWN) {
		spawn_daemon(socket);
		send_request(socket, &buf);
	}
	strbuf_release(&buf);
}