
    buf.append(" [", 2);

	buf.Printf("%d<=%d", (int)theGetSize, (int)thePutSize);
    if (theBodySize >= 0)
        buf.Printf("<=%d", (int)theBodySize);
	else
		buf.append("<=?", 3);

