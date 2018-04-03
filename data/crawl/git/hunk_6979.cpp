 		if (is_null_sha1(spec->sha1))
 			printf("D %s\n", spec->path);
 		else {
-			struct object *object = lookup_object(spec->sha1);
-			printf("M %06o :%d %s\n", spec->mode,
-			       get_object_mark(object), spec->path);
+			/*
+			 * Links refer to objects in another repositories;
+			 * output the SHA-1 verbatim.
+			 */
+			if (S_ISGITLINK(spec->mode))
+				printf("M %06o %s %s\n", spec->mode,
+				       sha1_to_hex(spec->sha1), spec->path);
+			else {
+				struct object *object = lookup_object(spec->sha1);
+				printf("M %06o :%d %s\n", spec->mode,
+				       get_object_mark(object), spec->path);
+			}
 		}
 	}
 }
