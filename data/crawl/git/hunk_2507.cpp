 			p = process_blob((struct blob *)obj, p, NULL, name);
 			continue;
 		}
-		die("unknown pending object %s (%s)", sha1_to_hex(obj->sha1), name);
+		die("unknown pending object %s (%s)", oid_to_hex(&obj->oid), name);
 	}
 
 	while (objects) {
