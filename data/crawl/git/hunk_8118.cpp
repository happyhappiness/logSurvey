 	}
 
 	if (nr_deltas) {
+		unsigned nr_done = 0;
+		if (progress)
+			start_progress(&progress_state,
+				       "Deltifying %u objects...", "",
+				       nr_deltas);
 		qsort(delta_list, n, sizeof(*delta_list), type_size_sort);
-		find_deltas(delta_list, n, nr_deltas, window+1, depth);
+		find_deltas(delta_list, n, window+1, depth, &nr_done);
+		if (progress)
+			stop_progress(&progress_state);
+		if (nr_done != nr_deltas)
+			die("inconsistency with delta count");
 	}
 	free(delta_list);
 }