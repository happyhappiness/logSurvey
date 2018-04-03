		if (check_to_send_update(ref, args) < 0)
			continue;

		old_hex = oid_to_hex(&ref->old_oid);
		new_hex = oid_to_hex(&ref->new_oid);
		if (!cmds_sent) {
			packet_buf_write(&req_buf,
					 "%s %s %s%c%s",
