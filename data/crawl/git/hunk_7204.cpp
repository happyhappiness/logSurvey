 		pretty_print_commit(revs.commit_format, commit,
 				    &buf, revs.abbrev, NULL, NULL,
 				    revs.date_mode, 0);
-		if (buf.len)
-			printf("%s%c", buf.buf, hdr_termination);
+		if (revs.graph) {
+			if (buf.len) {
+				if (revs.commit_format != CMIT_FMT_ONELINE)
+					graph_show_oneline(revs.graph);
+
+				graph_show_commit_msg(revs.graph, &buf);
+
+				/*
+				 * Add a newline after the commit message.
+				 *
+				 * Usually, this newline produces a blank
+				 * padding line between entries, in which case
+				 * we need to add graph padding on this line.
+				 *
+				 * However, the commit message may not end in a
+				 * newline.  In this case the newline simply
+				 * ends the last line of the commit message,
+				 * and we don't need any graph output.  (This
+				 * always happens with CMIT_FMT_ONELINE, and it
+				 * happens with CMIT_FMT_USERFORMAT when the
+				 * format doesn't explicitly end in a newline.)
+				 */
+				if (buf.len && buf.buf[buf.len - 1] == '\n')
+					graph_show_padding(revs.graph);
+				putchar('\n');
+			} else {
+				/*
+				 * If the message buffer is empty, just show
+				 * the rest of the graph output for this
+				 * commit.
+				 */
+				if (graph_show_remainder(revs.graph))
+					putchar('\n');
+			}
+		} else {
+			if (buf.len)
+				printf("%s%c", buf.buf, hdr_termination);
+		}
 		strbuf_release(&buf);
+	} else {
+		if (graph_show_remainder(revs.graph))
+			putchar('\n');
 	}
 	maybe_flush_or_die(stdout, "stdout");
 	finish_commit(commit);
