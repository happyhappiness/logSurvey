 		       oid_to_hex(&suspect->commit->object.oid),
 		       ent->s_lno + 1, ent->lno + 1, ent->num_lines);
 		emit_one_suspect_detail(suspect, 0);
-		write_filename_info(suspect->path);
+		write_filename_info(suspect);
 		maybe_flush_or_die(stdout, "stdout");
 	}
 	pi->blamed_lines += ent->num_lines;
