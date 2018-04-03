		if (!len) {
			if (have_obj.nr == 0 || multi_ack)
				packet_write(1, "NAK\n");
			continue;
		}
		strip(line, len);
