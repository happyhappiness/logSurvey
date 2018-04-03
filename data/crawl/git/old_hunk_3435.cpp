	const char *hex = sha1_to_hex(graft->sha1);
	if (graft->nr_parent != -1)
		return 0;
	data->count++;
	if (data->use_pack_protocol)
		packet_buf_write(data->out, "shallow %s", hex);
