 
 /*
  * Generic implementation of hash-based key-value mappings.
- * See Documentation/technical/api-hashmap.txt.
+ *
+ * An example that maps long to a string:
+ * For the sake of the example this allows to lookup exact values, too
+ * (i.e. it is operated as a set, the value is part of the key)
+ * -------------------------------------
+ *
+ * struct hashmap map;
+ * struct long2string {
+ *     struct hashmap_entry ent; // must be the first member!
+ *     long key;
+ *     char value[FLEX_ARRAY];   // be careful with allocating on stack!
+ * };
+ *
+ * #define COMPARE_VALUE 1
+ *
+ * static int long2string_cmp(const struct long2string *e1,
+ *                            const struct long2string *e2,
+ *                            const void *keydata, const void *userdata)
+ * {
+ *     char *string = keydata;
+ *     unsigned *flags = (unsigned*)userdata;
+ *
+ *     if (flags & COMPARE_VALUE)
+ *         return !(e1->key == e2->key) || (keydata ?
+ *                  strcmp(e1->value, keydata) : strcmp(e1->value, e2->value));
+ *     else
+ *         return !(e1->key == e2->key);
+ * }
+ *
+ * int main(int argc, char **argv)
+ * {
+ *     long key;
+ *     char *value, *action;
+ *
+ *     unsigned flags = ALLOW_DUPLICATE_KEYS;
+ *
+ *     hashmap_init(&map, (hashmap_cmp_fn) long2string_cmp, &flags, 0);
+ *
+ *     while (scanf("%s %l %s", action, key, value)) {
+ *
+ *         if (!strcmp("add", action)) {
+ *             struct long2string *e;
+ *             e = malloc(sizeof(struct long2string) + strlen(value));
+ *             hashmap_entry_init(e, memhash(&key, sizeof(long)));
+ *             e->key = key;
+ *             memcpy(e->value, value, strlen(value));
+ *             hashmap_add(&map, e);
+ *         }
+ *
+ *         if (!strcmp("print_all_by_key", action)) {
+ *             flags &= ~COMPARE_VALUE;
+ *
+ *             struct long2string k;
+ *             hashmap_entry_init(&k, memhash(&key, sizeof(long)));
+ *             k.key = key;
+ *
+ *             struct long2string *e = hashmap_get(&map, &k, NULL);
+ *             if (e) {
+ *                 printf("first: %l %s\n", e->key, e->value);
+ *                 while (e = hashmap_get_next(&map, e))
+ *                     printf("found more: %l %s\n", e->key, e->value);
+ *             }
+ *         }
+ *
+ *         if (!strcmp("has_exact_match", action)) {
+ *             flags |= COMPARE_VALUE;
+ *
+ *             struct long2string *e;
+ *             e = malloc(sizeof(struct long2string) + strlen(value));
+ *             hashmap_entry_init(e, memhash(&key, sizeof(long)));
+ *             e->key = key;
+ *             memcpy(e->value, value, strlen(value));
+ *
+ *             printf("%s found\n", hashmap_get(&map, e, NULL) ? "" : "not");
+ *         }
+ *
+ *         if (!strcmp("has_exact_match_no_heap_alloc", action)) {
+ *             flags |= COMPARE_VALUE;
+ *
+ *             struct long2string e;
+ *             hashmap_entry_init(e, memhash(&key, sizeof(long)));
+ *             e.key = key;
+ *
+ *             printf("%s found\n", hashmap_get(&map, e, value) ? "" : "not");
+ *         }
+ *
+ *         if (!strcmp("end", action)) {
+ *             hashmap_free(&map, 1);
+ *             break;
+ *         }
+ *     }
+ * }
  */
 
-/* FNV-1 functions */
-
+/*
+ * Ready-to-use hash functions for strings, using the FNV-1 algorithm (see
+ * http://www.isthe.com/chongo/tech/comp/fnv).
+ * `strhash` and `strihash` take 0-terminated strings, while `memhash` and
+ * `memihash` operate on arbitrary-length memory.
+ * `strihash` and `memihash` are case insensitive versions.
+ * `memihash_cont` is a variant of `memihash` that allows a computation to be
+ * continued with another chunk of data.
+ */
 extern unsigned int strhash(const char *buf);
 extern unsigned int strihash(const char *buf);
 extern unsigned int memhash(const void *buf, size_t len);
 extern unsigned int memihash(const void *buf, size_t len);
 extern unsigned int memihash_cont(unsigned int hash_seed, const void *buf, size_t len);
 
+/*
+ * Converts a cryptographic hash (e.g. SHA-1) into an int-sized hash code
+ * for use in hash tables. Cryptographic hashes are supposed to have
+ * uniform distribution, so in contrast to `memhash()`, this just copies
+ * the first `sizeof(int)` bytes without shuffling any bits. Note that
+ * the results will be different on big-endian and little-endian
+ * platforms, so they should not be stored or transferred over the net.
+ */
 static inline unsigned int sha1hash(const unsigned char *sha1)
 {
 	/*
