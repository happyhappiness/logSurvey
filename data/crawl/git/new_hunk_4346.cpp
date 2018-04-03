
		if (!len) {
			if (multi_ack == 2 && got_common
			    && !got_other && ok_to_give_up())
				packet_write(1, "ACK %s ready\n", last_hex);
			if (have_obj.nr == 0 || multi_ack)
				packet_write(1, "NAK\n");
			if (stateless_rpc)
				exit(0);
			got_common = 0;
