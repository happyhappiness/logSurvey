 			seen_this = 1;
 			graph_output_commit_char(graph, sb);
 
-			if (graph->num_parents < 2)
+			if (graph->num_parents < 3)
 				strbuf_addch(sb, ' ');
-			else if (graph->num_parents == 2)
-				strbuf_addstr(sb, "  ");
 			else {
 				int num_dashes =
 					((graph->num_parents - 2) * 2) - 1;
 				for (j = 0; j < num_dashes; j++)
 					strbuf_addch(sb, '-');
 				strbuf_addstr(sb, ". ");
 			}
-		} else if (seen_this && (graph->num_parents > 1)) {
+		} else if (seen_this && (graph->num_parents > 2)) {
 			strbuf_addstr(sb, "\\ ");
+		} else if (seen_this && (graph->num_parents == 2)) {
+			/*
+			 * This is a 2-way merge commit.
+			 * There is no GRAPH_PRE_COMMIT stage for 2-way
+			 * merges, so this is the first line of output
+			 * for this commit.  Check to see what the previous
+			 * line of output was.
+			 *
+			 * If it was GRAPH_POST_MERGE, the branch line
+			 * coming into this commit may have been '\',
+			 * and not '|' or '/'.  If so, output the branch
+			 * line as '\' on this line, instead of '|'.  This
+			 * makes the output look nicer.
+			 */
+			if (graph->prev_state == GRAPH_POST_MERGE &&
+			    graph->prev_commit_index < i)
+				strbuf_addstr(sb, "\\ ");
+			else
+				strbuf_addstr(sb, "| ");
 		} else {
 			strbuf_addstr(sb, "| ");
 		}
