	return parse_sha1_header_extended(hdr, &oi, 0);
}

const unsigned char *nth_packed_object_sha1(struct packed_git *p,
					    uint32_t n)
{
