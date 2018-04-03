			strbuf_addstr(&cap, " ofs-delta");
		if (push_cert_nonce)
			strbuf_addf(&cap, " push-cert=%s", push_cert_nonce);
		strbuf_addf(&cap, " agent=%s", git_user_agent_sanitized());
		packet_write(1, "%s %s%c%s\n",
			     sha1_to_hex(sha1), path, 0, cap.buf);
