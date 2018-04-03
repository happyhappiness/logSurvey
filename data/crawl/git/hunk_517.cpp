 			struct object *object;
 			if (get_oid_hex(arg, &oid))
 				die("invalid shallow line: %s", line);
-			object = parse_object(oid.hash);
+			object = parse_object(&oid);
 			if (!object)
 				continue;
 			if (object->type != OBJ_COMMIT)
