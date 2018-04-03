
		sb.final_buf = read_sha1_file(o->blob_sha1, &type,
					      &sb.final_buf_size);
	}
	num_read_blob++;
	lno = prepare_lines(&sb);