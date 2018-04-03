 			&reuse_packfile_offset)) {
 		assert(reuse_packfile_objects);
 		nr_result += reuse_packfile_objects;
-
-		if (progress) {
-			fprintf(stderr, "Reusing existing pack: %d, done.\n",
-				reuse_packfile_objects);
-			fflush(stderr);
-		}
+		display_progress(progress_state, nr_result);
 	}
 
 	traverse_bitmap_commit_list(&add_object_entry_from_bitmap);