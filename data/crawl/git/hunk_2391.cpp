 		case OBJ_COMMIT:
 			break;
 		case OBJ_BLOB:
-			export_blob(get_object_hash(commit->object));
+			export_blob(commit->object.oid.hash);
 			continue;
 		default: /* OBJ_TAG (nested tags) is already handled */
 			warning("Tag points to object of unexpected type %s, skipping.",