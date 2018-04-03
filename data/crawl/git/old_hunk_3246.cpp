		return -1;
	if (oi->disk_sizep)
		*oi->disk_sizep = mapsize;
	if (unpack_sha1_header(&stream, map, mapsize, hdr, sizeof(hdr)) < 0)
		status = error("unable to unpack %s header",
			       sha1_to_hex(sha1));
	else if ((status = parse_sha1_header(hdr, &size)) < 0)
		status = error("unable to parse %s header", sha1_to_hex(sha1));
	else if (oi->sizep)
		*oi->sizep = size;
	git_inflate_end(&stream);
	munmap(map, mapsize);
	if (oi->typep)
		*oi->typep = status;
	return 0;
}

