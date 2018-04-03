		} else if (!strcmp("size", cmd)) {

			/* print table sizes */
			printf("%u %u\n", map.tablesize, map.size);

		} else if (!strcmp("intern", cmd) && l1) {
