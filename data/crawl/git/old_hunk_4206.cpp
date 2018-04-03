			char *old_hex = sha1_to_hex(ref->old_sha1);
			char *new_hex = sha1_to_hex(ref->new_sha1);

			if (!cmds_sent && (status_report || use_sideband)) {
				packet_buf_write(&req_buf, "%s %s %s%c%s%s",
					old_hex, new_hex, ref->name, 0,
					status_report ? " report-status" : "",
					use_sideband ? " side-band-64k" : "");
			}
			else
				packet_buf_write(&req_buf, "%s %s %s",
