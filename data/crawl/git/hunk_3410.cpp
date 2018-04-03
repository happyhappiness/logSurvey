 	}
 }
 
+static int get_object_list_from_bitmap(struct rev_info *revs)
+{
+	if (prepare_bitmap_walk(revs) < 0)
+		return -1;
+
+	if (!reuse_partial_packfile_from_bitmap(
+			&reuse_packfile,
+			&reuse_packfile_objects,
+			&reuse_packfile_offset)) {
+		assert(reuse_packfile_objects);
+		nr_result += reuse_packfile_objects;
+
+		if (progress) {
+			fprintf(stderr, "Reusing existing pack: %d, done.\n",
+				reuse_packfile_objects);
+			fflush(stderr);
+		}
+	}
+
+	traverse_bitmap_commit_list(&add_object_entry_from_bitmap);
+	return 0;
+}
+
 static void get_object_list(int ac, const char **av)
 {
 	struct rev_info revs;
