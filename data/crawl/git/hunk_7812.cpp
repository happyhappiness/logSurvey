 					   (nr_objects + nr_unresolved + 1)
 					   * sizeof(*objects));
 			fix_unresolved_deltas(nr_unresolved);
-			stop_progress(&progress);
-			if (verbose)
-				fprintf(stderr, "%d objects were added to complete this thin pack.\n",
-					nr_objects - nr_objects_initial);
+			sprintf(msg, "completed with %d local objects",
+				nr_objects - nr_objects_initial);
+			stop_progress_msg(&progress, msg);
 			fixup_pack_header_footer(output_fd, sha1,
-				curr_pack, nr_objects);
+						 curr_pack, nr_objects);
 		}
 		if (nr_deltas != nr_resolved_deltas)
 			die("pack has %d unresolved deltas",
