			char *new_hex = sha1_to_hex(ref->new_sha1);

			if (ask_for_status_report) {
				packet_buf_write(&req_buf, "%s %s %s%c%s",
					old_hex, new_hex, ref->name, 0,
					"report-status");
				ask_for_status_report = 0;
				expect_status_report = 1;
			}
			else
				packet_buf_write(&req_buf, "%s %s %s",
					old_hex, new_hex, ref->name);
		}
		ref->status = expect_status_report ?
			REF_STATUS_EXPECTING_REPORT :
			REF_STATUS_OK;
	}

	if (args->stateless_rpc) {
		if (!args->dry_run) {
			packet_buf_flush(&req_buf);
			send_sideband(out, -1, req_buf.buf, req_buf.len, LARGE_PACKET_MAX);
		}
	} else {
		safe_write(out, req_buf.buf, req_buf.len);
		packet_flush(out);
	}
	strbuf_release(&req_buf);

	if (new_refs && !args->dry_run) {
		if (pack_objects(out, remote_refs, extra_have, args) < 0) {
			for (ref = remote_refs; ref; ref = ref->next)
				ref->status = REF_STATUS_NONE;
			return -1;
		}
	}
	if (args->stateless_rpc && !args->dry_run)
		packet_flush(out);

	if (expect_status_report)
		ret = receive_status(in, remote_refs);
	else
		ret = 0;
	if (args->stateless_rpc)
		packet_flush(out);

	if (ret < 0)
		return ret;
