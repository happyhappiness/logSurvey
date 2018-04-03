}

/*
 * Convert a partial SHA1 hex string to the corresponding partial SHA1 value.
 * - hex      - Partial SHA1 segment in ASCII hex format
 * - hex_len  - Length of above segment. Must be multiple of 2 between 0 and 40
 * - oid      - Partial SHA1 value is written here
 * Return 0 on success or -1 on error (invalid arguments or input not
 * in hex format).
 */
static int get_oid_hex_segment(const char *hex, unsigned int hex_len,
		unsigned char *oid)
{
	unsigned int i, len = hex_len >> 1;
	if (hex_len % 2 != 0)
		return -1;
	for (i = 0; i < len; i++) {
		unsigned int val = (hexval(hex[0]) << 4) | hexval(hex[1]);
		if (val & ~0xff)
			return -1;
		*oid++ = val;
		hex += 2;
	}
	return 0;
}
