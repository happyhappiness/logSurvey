 				if (from <= last_shown)
 					from = last_shown + 1;
 				if (last_shown && from != last_shown + 1)
-					printf(hunk_mark);
+					fputs(hunk_mark, stdout);
 				while (from < lno) {
 					pcl = &prev[lno-from-1];
 					show_line(opt, pcl->bol, pcl->eol,
