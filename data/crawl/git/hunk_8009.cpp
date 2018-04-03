 		o = lookup_object(remote);
 		if (!o || !(o->flags & COMPLETE)) {
 			retval = 0;
-			if (!verbose)
+			if (!args.verbose)
 				continue;
 			fprintf(stderr,
 				"want %s (%s)\n", sha1_to_hex(remote),
