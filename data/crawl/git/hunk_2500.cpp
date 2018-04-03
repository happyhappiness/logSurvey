 	case OBJ_TAG:
 		return fsck_walk_tag((struct tag *)obj, data, options);
 	default:
-		error("Unknown object type for %s", sha1_to_hex(obj->sha1));
+		error("Unknown object type for %s", oid_to_hex(&obj->oid));
 		return -1;
 	}
 }
