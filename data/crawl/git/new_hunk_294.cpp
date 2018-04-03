	return parse_sha1_header_extended(hdr, &oi, 0);
}

off_t find_pack_entry_one(const unsigned char *sha1,
				  struct packed_git *p)
{