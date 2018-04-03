 	if (!obj->used) {
 		printf("dangling %s %s\n", typename(obj->type),
 		       sha1_to_hex(obj->sha1));
+		if (write_lost_and_found) {
+			char *filename = git_path("lost-found/%s/%s",
+				obj->type == OBJ_COMMIT ? "commit" : "other",
+				sha1_to_hex(obj->sha1));
+			FILE *f;
+
+			if (safe_create_leading_directories(filename)) {
+				error("Could not create lost-found");
+				return;
+			}
+			if (!(f = fopen(filename, "w")))
+				die("Could not open %s", filename);
+			fprintf(f, "%s\n", sha1_to_hex(obj->sha1));
+			fclose(f);
+		}
 		return;
 	}
 
