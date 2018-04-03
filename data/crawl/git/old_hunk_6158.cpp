		hex[40] = 0;
		if (get_sha1_hex(hex, sha1))
			die("internal error");
		if (has_sha1_pack(sha1, NULL))
			(*packed_loose)++;
	}
}
