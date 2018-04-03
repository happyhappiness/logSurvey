 				/* make sure the real parents are parsed */
 				unregister_shallow(object->sha1);
 				object->parsed = 0;
-				parse_commit((struct commit *)object);
+				if (parse_commit((struct commit *)object))
+					die("invalid commit");
 				parents = ((struct commit *)object)->parents;
 				while (parents) {
 					add_object_array(&parents->item->object,