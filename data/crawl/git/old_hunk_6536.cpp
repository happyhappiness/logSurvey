	stream.next_out = delta_head;
	stream.avail_out = sizeof(delta_head);

	inflateInit(&stream);
	do {
		in = use_pack(p, w_curs, curpos, &stream.avail_in);
		stream.next_in = in;
		st = inflate(&stream, Z_FINISH);
		curpos += stream.next_in - in;
	} while ((st == Z_OK || st == Z_BUF_ERROR) &&
		 stream.total_out < sizeof(delta_head));
	inflateEnd(&stream);
	if ((st != Z_STREAM_END) && stream.total_out != sizeof(delta_head))
		die("delta data unpack-initial failed");

