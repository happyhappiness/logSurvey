 		} else if (obj->type == OBJ_BLOB) {
 			if (2 <= blobs)
 				die(_("more than two blobs given: '%s'"), name);
-			hashcpy(blob[blobs].sha1, obj->sha1);
+			hashcpy(blob[blobs].sha1, get_object_hash(*obj));
 			blob[blobs].name = name;
 			blob[blobs].mode = entry->mode;
 			blobs++;
