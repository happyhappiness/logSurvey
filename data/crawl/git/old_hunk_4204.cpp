	else
		packet_write(1, "%s %s%c%s%s\n",
			     sha1_to_hex(sha1), path, 0,
			     " report-status delete-refs side-band-64k",
			     prefer_ofs_delta ? " ofs-delta" : "");
	sent_capabilities = 1;
	return 0;
