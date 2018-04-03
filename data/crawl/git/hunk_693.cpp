 		if (skip_prefix(line.buf, "append ", &arg)) {
 			if (get_oid_hex(arg, &oid))
 				die("not a hexadecimal SHA1: %s", arg);
-			sha1_array_append(&array, &oid);
+			oid_array_append(&array, &oid);
 		} else if (skip_prefix(line.buf, "lookup ", &arg)) {
 			if (get_oid_hex(arg, &oid))
 				die("not a hexadecimal SHA1: %s", arg);
-			printf("%d\n", sha1_array_lookup(&array, &oid));
+			printf("%d\n", oid_array_lookup(&array, &oid));
 		} else if (!strcmp(line.buf, "clear"))
-			sha1_array_clear(&array);
+			oid_array_clear(&array);
 		else if (!strcmp(line.buf, "for_each_unique"))
-			sha1_array_for_each_unique(&array, print_oid, NULL);
+			oid_array_for_each_unique(&array, print_oid, NULL);
 		else
 			die("unknown command: %s", line.buf);
 	}
