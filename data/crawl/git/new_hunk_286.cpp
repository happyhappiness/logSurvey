 * Convert a partial SHA1 hex string to the corresponding partial SHA1 value.
 * - hex      - Partial SHA1 segment in ASCII hex format
 * - hex_len  - Length of above segment. Must be multiple of 2 between 0 and 40
 * - oid      - Partial SHA1 value is written here
 * - oid_len  - Max #bytes to store in sha1, Must be >= hex_len / 2, and < 20
 * Return 0 on success or -1 on error (invalid arguments or input not
 * in hex format). Pad oid with NULs up to oid_len.
 */
static int get_oid_hex_segment(const char *hex, unsigned int hex_len,
		unsigned char *oid, unsigned int oid_len)
