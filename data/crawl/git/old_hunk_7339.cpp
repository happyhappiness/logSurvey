		}

		if (!fetching)
			packet_write(fd[1], "want %s%s%s%s%s%s%s\n",
				     sha1_to_hex(remote),
				     (multi_ack ? " multi_ack" : ""),
				     (use_sideband == 2 ? " side-band-64k" : ""),
				     (use_sideband == 1 ? " side-band" : ""),
				     (args.use_thin_pack ? " thin-pack" : ""),
				     (args.no_progress ? " no-progress" : ""),
				     " ofs-delta");
		else
			packet_write(fd[1], "want %s\n", sha1_to_hex(remote));
