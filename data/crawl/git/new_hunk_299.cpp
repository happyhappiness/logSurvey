	return parse_sha1_header_extended(hdr, &oi, 0);
}

static off_t get_delta_base(struct packed_git *p,
				    struct pack_window **w_curs,
				    off_t *curpos,