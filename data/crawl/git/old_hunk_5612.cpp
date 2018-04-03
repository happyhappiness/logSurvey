				sha1_to_hex(commit_graft[i]->sha1);
			count++;
			if (use_pack_protocol)
				packet_write(fd, "shallow %s", hex);
			else {
				if (write_in_full(fd, hex,  40) != 40)
					break;
				if (write_str_in_full(fd, "\n") != 1)
					break;
			}
		}
	return count;
