				sha1_to_hex(commit_graft[i]->sha1);
			count++;
			if (use_pack_protocol)
				packet_buf_write(out, "shallow %s", hex);
			else {
				strbuf_addstr(out, hex);
				strbuf_addch(out, '\n');
			}
		}
	return count;
