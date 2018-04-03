
/*
 * Generic implementation of hash-based key-value mappings.
 * See Documentation/technical/api-hashmap.txt.
 */

/* FNV-1 functions */

extern unsigned int strhash(const char *buf);
extern unsigned int strihash(const char *buf);
extern unsigned int memhash(const void *buf, size_t len);
extern unsigned int memihash(const void *buf, size_t len);
extern unsigned int memihash_cont(unsigned int hash_seed, const void *buf, size_t len);

static inline unsigned int sha1hash(const unsigned char *sha1)
{
	/*
