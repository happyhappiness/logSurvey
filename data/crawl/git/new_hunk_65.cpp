			printf("%u %u\n", map.tablesize,
			       hashmap_get_size(&map));

		} else if (!strcmp("intern", cmd) && p1) {

			/* test that strintern works */
			const char *i1 = strintern(p1);
