 			continue;
 		}
 		if (bases_count < ARRAY_SIZE(bases)-1) {
-			unsigned char *sha = xmalloc(20);
-			if (get_sha1(argv[i], sha))
+			struct object_id *oid = xmalloc(sizeof(struct object_id));
+			if (get_oid(argv[i], oid))
 				die("Could not parse object '%s'", argv[i]);
-			bases[bases_count++] = sha;
+			bases[bases_count++] = oid;
 		}
 		else
 			warning("Cannot handle more than %d bases. "
