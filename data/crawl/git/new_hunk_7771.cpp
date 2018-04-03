	if (!args.keep_pack && unpack_limit) {
		struct pack_header header;

		if (read_pack_header(demux.out, &header))
			die("protocol error: bad pack header");
		snprintf(hdr_arg, sizeof(hdr_arg), "--pack_header=%u,%u",
			 ntohl(header.hdr_version), ntohl(header.hdr_entries));
