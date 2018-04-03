 				    &bottom, &top, sb.path))
 			usage(blame_usage);
 		if (lno < top || ((lno || bottom) && lno < bottom))
-			die("file %s has only %lu lines", path, lno);
+			die(Q_("file %s has only %lu line",
+			       "file %s has only %lu lines",
+			       lno), path, lno);
 		if (bottom < 1)
 			bottom = 1;
 		if (top < 1)
