}

/*
 * Read `len` pairs of hexadecimal digits from `hex` and write the
 * values to `binary` as `len` bytes. Return 0 on success, or -1 if
 * the input does not consist of hex digits).
 */
static int hex_to_bytes(unsigned char *binary, const char *hex, size_t len)
{
	for (; len; len--, hex += 2) {
		unsigned int val = (hexval(hex[0]) << 4) | hexval(hex[1]);

		if (val & ~0xff)
			return -1;
		*binary++ = val;
	}
	return 0;
}
