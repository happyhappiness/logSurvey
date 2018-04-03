
    buf.append(" [", 2);

	buf.Printf("%"PRIu64"<=%"PRIu64, theGetSize, thePutSize);
    if (theBodySize >= 0)
        buf.Printf("<=%"PRId64, theBodySize);
	else
		buf.append("<=?", 3);

