
		p1 = strtok(NULL, DELIM);
		if (p1) {
			l1 = strlen(p1);
			hash = icase ? strihash(p1) : strhash(p1);
			p2 = strtok(NULL, DELIM);
			if (p2)
				l2 = strlen(p2);
		}

		if (!strcmp("hash", cmd) && l1) {

			/* print results of different hash functions */
			printf("%u %u %u %u\n", strhash(p1), memhash(p1, l1),
					strihash(p1), memihash(p1, l1));

		} else if (!strcmp("add", cmd) && l1 && l2) {

			/* create entry with key = p1, value = p2 */
			entry = alloc_test_entry(hash, p1, l1, p2, l2);

			/* add to hashmap */
			hashmap_add(&map, entry);

		} else if (!strcmp("put", cmd) && l1 && l2) {

			/* create entry with key = p1, value = p2 */
			entry = alloc_test_entry(hash, p1, l1, p2, l2);

			/* add / replace entry */
			entry = hashmap_put(&map, entry);
