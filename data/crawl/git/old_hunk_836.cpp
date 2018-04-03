
extern int has_sha1_pack(const unsigned char *sha1);

/*
 * Return true iff we have an object named sha1, whether local or in
 * an alternate object database, and whether packed or loose.  This
