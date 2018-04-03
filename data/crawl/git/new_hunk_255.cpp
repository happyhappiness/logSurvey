		} else if (!strcmp("size", cmd)) {

			/* print table sizes */
			printf("%u %u\n", map.tablesize,
			       hashmap_get_size(&map));

		} else if (!strcmp("intern", cmd) && l1) {
