 			if (!(f = fopen(filename, "w")))
 				die_errno("Could not open '%s'", filename);
 			if (obj->type == OBJ_BLOB) {
-				if (stream_blob_to_fd(fileno(f), get_object_hash(*obj), NULL, 1))
+				if (stream_blob_to_fd(fileno(f), obj->oid.hash, NULL, 1))
 					die_errno("Could not write '%s'", filename);
 			} else
 				fprintf(f, "%s\n", oid_to_hex(&obj->oid));
