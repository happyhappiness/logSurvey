			if (multi_ack == 2 && got_common
			    && !got_other && ok_to_give_up()) {
				sent_ready = 1;
				packet_write(1, "ACK %s ready\n", last_hex);
			}
			if (have_obj.nr == 0 || multi_ack)
				packet_write(1, "NAK\n");

			if (no_done && sent_ready) {
				packet_write(1, "ACK %s\n", last_hex);
				return 0;
			}
			if (stateless_rpc)
