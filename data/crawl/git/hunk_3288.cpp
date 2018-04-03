 			}
 			if (obj->type == OBJ_COMMIT) {
 				struct commit *commit = (struct commit *) obj;
-				commit->buffer = NULL;
+				if (detach_commit_buffer(commit) != data)
+					die("BUG: parse_object_buffer transmogrified our buffer");
 			}
 			obj->flags |= FLAG_CHECKED;
 		}
