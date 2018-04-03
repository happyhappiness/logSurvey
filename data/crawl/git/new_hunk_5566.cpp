		if (!len) {
			if (have_obj.nr == 0 || multi_ack)
				packet_write(1, "NAK\n");
			if (stateless_rpc)
				exit(0);
			continue;
		}
		strip(line, len);
