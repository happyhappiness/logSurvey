extern int get_sha1_hex(const char *hex, unsigned char *sha1);
extern int get_oid_hex(const char *hex, struct object_id *sha1);

extern char *sha1_to_hex(const unsigned char *sha1);	/* static buffer result! */
extern char *oid_to_hex(const struct object_id *oid);	/* same static buffer as sha1_to_hex */

