	return parse_sha1_header_extended(hdr, &oi, 0);
}

static int fill_pack_entry(const unsigned char *sha1,
			   struct pack_entry *e,
			   struct packed_git *p)