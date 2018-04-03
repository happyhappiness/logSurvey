 				free(filename);
 				return;
 			}
-			if (!(f = fopen(filename, "w")))
-				die_errno("Could not open '%s'", filename);
+			f = xfopen(filename, "w");
 			if (obj->type == OBJ_BLOB) {
 				if (stream_blob_to_fd(fileno(f), &obj->oid, NULL, 1))
 					die_errno("Could not write '%s'", filename);
