				     (args.use_thin_pack ? " thin-pack" : ""),
				     (args.no_progress ? " no-progress" : ""),
				     (args.include_tag ? " include-tag" : ""),
				     " ofs-delta");
		else
			packet_write(fd[1], "want %s\n", sha1_to_hex(remote));
		fetching++;
