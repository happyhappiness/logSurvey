 
 	case 0:
 		if (type_from_string(exp_type) == OBJ_BLOB) {
-			unsigned char blob_sha1[20];
-			if (sha1_object_info(sha1, NULL) == OBJ_TAG) {
-				char *buffer = read_sha1_file(sha1, &type, &size);
+			struct object_id blob_oid;
+			if (sha1_object_info(oid.hash, NULL) == OBJ_TAG) {
+				char *buffer = read_sha1_file(oid.hash, &type, &size);
 				const char *target;
 				if (!skip_prefix(buffer, "object ", &target) ||
-				    get_sha1_hex(target, blob_sha1))
-					die("%s not a valid tag", sha1_to_hex(sha1));
+				    get_oid_hex(target, &blob_oid))
+					die("%s not a valid tag", oid_to_hex(&oid));
 				free(buffer);
 			} else
-				hashcpy(blob_sha1, sha1);
+				oidcpy(&blob_oid, &oid);
 
-			if (sha1_object_info(blob_sha1, NULL) == OBJ_BLOB)
-				return stream_blob_to_fd(1, blob_sha1, NULL, 0);
+			if (sha1_object_info(blob_oid.hash, NULL) == OBJ_BLOB)
+				return stream_blob_to_fd(1, blob_oid.hash, NULL, 0);
 			/*
 			 * we attempted to dereference a tag to a blob
 			 * and failed; there may be new dereference
 			 * mechanisms this code is not aware of.
 			 * fall-back to the usual case.
 			 */
 		}
-		buf = read_object_with_reference(sha1, exp_type, &size, NULL);
+		buf = read_object_with_reference(oid.hash, exp_type, &size, NULL);
 		break;
 
 	default:
