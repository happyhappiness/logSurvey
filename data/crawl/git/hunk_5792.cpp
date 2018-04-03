 					from = lno - opt->pre_context;
 				else
 					from = 1;
-				if (from <= last_shown)
-					from = last_shown + 1;
-				if (last_shown && from != last_shown + 1)
-					fputs(hunk_mark, stdout);
+				if (from <= opt->last_shown)
+					from = opt->last_shown + 1;
 				while (from < lno) {
 					pcl = &prev[lno-from-1];
 					show_line(opt, pcl->bol, pcl->eol,
 						  name, from, '-');
 					from++;
 				}
-				last_shown = lno-1;
 			}
-			if (last_shown && lno != last_shown + 1)
-				fputs(hunk_mark, stdout);
 			if (!opt->count)
 				show_line(opt, bol, eol, name, lno, ':');
-			last_shown = last_hit = lno;
+			last_hit = lno;
 		}
 		else if (last_hit &&
 			 lno <= last_hit + opt->post_context) {
 			/* If the last hit is within the post context,
 			 * we need to show this line.
 			 */
-			if (last_shown && lno != last_shown + 1)
-				fputs(hunk_mark, stdout);
 			show_line(opt, bol, eol, name, lno, '-');
-			last_shown = lno;
 		}
 		if (opt->pre_context) {
 			memmove(prev+1, prev,
