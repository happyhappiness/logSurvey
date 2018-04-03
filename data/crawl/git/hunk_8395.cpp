 				die("unable to rename temporary index file: %s",
 				    strerror(errno));
 			puts(sha1_to_hex(object_list_sha1));
+		}
+
+		/* mark written objects as written to previous pack */
+		for (j = 0; j < nr_written; j++) {
+			written_list[j]->offset = (off_t)-1;
+		}
+		nr_remaining -= nr_written;
+	} while (nr_remaining && i < nr_objects);
+
+	free(written_list);
+	if (do_progress)
+		stop_progress(&progress_state);
+	if (written != nr_result)
+		die("wrote %u objects while expecting %u", written, nr_result);
+	for (j = 0; i < nr_objects; i++) {
+		struct object_entry *e = objects + i;
+		j += !e->offset && !e->preferred_base;
 	}
+	if (j)
+		die("wrote %u objects as expected but %u unwritten", written, j);
 }
 
 static int sha1_sort(const void *_a, const void *_b)
