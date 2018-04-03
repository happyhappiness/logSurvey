 			object = parse_object(sha1);
 			if (!object)
 				die("did not find object for %s", line);
+			if (object->type != OBJ_COMMIT)
+				die("invalid shallow object %s", sha1_to_hex(sha1));
 			object->flags |= CLIENT_SHALLOW;
 			add_object_array(object, NULL, &shallows);
 			continue;