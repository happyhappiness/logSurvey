		if (check_to_send_update(ref, args) < 0)
			continue;

		old_hex = sha1_to_hex(ref->old_sha1);
		new_hex = sha1_to_hex(ref->new_sha1);
		if (!cmds_sent) {
			packet_buf_write(&req_buf,
					 "%s %s %s%c%s",
