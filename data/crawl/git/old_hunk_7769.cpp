				packet_write(out, "%s %s %s",
					old_hex, new_hex, ref->name);
		}
	}

	packet_flush(out);
