	} while ((st == Z_OK || st == Z_BUF_ERROR) &&
		 stream.total_out < sizeof(delta_head));
	inflateEnd(&stream);
	if ((st != Z_STREAM_END) && stream.total_out != sizeof(delta_head))
		die("delta data unpack-initial failed");

	/* Examine the initial part of the delta to figure out
	 * the result size.
