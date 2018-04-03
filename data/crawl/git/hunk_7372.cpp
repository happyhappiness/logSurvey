 			die("SHA1 COLLISION FOUND WITH %s !", sha1_to_hex(sha1));
 		free(has_data);
 	}
+	if (strict) {
+		if (type == OBJ_BLOB) {
+			struct blob *blob = lookup_blob(sha1);
+			if (blob)
+				blob->object.flags |= FLAG_CHECKED;
+			else
+				die("invalid blob object %s", sha1_to_hex(sha1));
+		} else {
+			struct object *obj;
+			int eaten;
+			void *buf = (void *) data;
+
+			/*
+			 * we do not need to free the memory here, as the
+			 * buf is deleted by the caller.
+			 */
+			obj = parse_object_buffer(sha1, type, size, buf, &eaten);
+			if (!obj)
+				die("invalid %s", typename(type));
+			if (fsck_object(obj, 1, fsck_error_function))
+				die("Error in object");
+			if (fsck_walk(obj, mark_link, 0))
+				die("Not all child objects of %s are reachable", sha1_to_hex(obj->sha1));
+
+			if (obj->type == OBJ_TREE) {
+				struct tree *item = (struct tree *) obj;
+				item->buffer = NULL;
+			}
+			if (obj->type == OBJ_COMMIT) {
+				struct commit *commit = (struct commit *) obj;
+				commit->buffer = NULL;
+			}
+			obj->flags |= FLAG_CHECKED;
+		}
+	}
 }
 
 static void resolve_delta(struct object_entry *delta_obj, void *base_data,
