				got_other = 1;
				if (multi_ack && ok_to_give_up()) {
					const char *hex = sha1_to_hex(sha1);
					if (multi_ack == 2)
						packet_write(1, "ACK %s ready\n", hex);
					else
						packet_write(1, "ACK %s continue\n", hex);
				}
				break;
