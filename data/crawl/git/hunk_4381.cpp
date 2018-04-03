 	fwrite(sb.buf, sb.len, 1, f);
 
 	if (!message) {
-		while ((commit = get_revision(&rev))) {
-			struct pretty_print_context ctx = {0};
-			ctx.date_mode = rev.date_mode;
-			strbuf_setlen(&sb, 0);
-			if (commit->object.flags & SYMMETRIC_LEFT) {
-				if (del)
-					strbuf_addstr(&sb, del);
-			}
-			else if (add)
-				strbuf_addstr(&sb, add);
-			format_commit_message(commit, format, &sb, &ctx);
-			if (reset)
-				strbuf_addstr(&sb, reset);
-			strbuf_addch(&sb, '\n');
-			fprintf(f, "%s", sb.buf);
-		}
+		print_submodule_summary(&rev, f, del, add, reset);
 		clear_commit_marks(left, ~0);
 		clear_commit_marks(right, ~0);
 	}
+
 	strbuf_release(&sb);
 }
 