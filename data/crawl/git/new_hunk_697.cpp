		} else if (skip_prefix(line.buf, "lookup ", &arg)) {
			if (get_oid_hex(arg, &oid))
				die("not a hexadecimal SHA1: %s", arg);
			printf("%d\n", sha1_array_lookup(&array, &oid));
		} else if (!strcmp(line.buf, "clear"))
			sha1_array_clear(&array);
		else if (!strcmp(line.buf, "for_each_unique"))