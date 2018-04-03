 		    sscanf(reserve, "%s %d %d %d %d %f %d %d %d",
 			s1, &d1, &d2, &d3, &d4, &f1, &d5, &d6, &d7);
 		    if (hasTables)
-			printf("<tr><td><B>%s</B><td>%d<td>%d<td>%d<td>%d<td>%4.2f<td>%d<td>%d<td>%d",
+			printf("<tr><td align=right><B>%s</B><td align=right>%d<td align=right>%d<td align=right>%d<td align=right>%d<td align=right>%4.2f<td align=right>%d<td align=right>%d<td align=right>%d",
 			    s1, d1, d2, d3, d4, f1, d5, d6, d7);
 		    else
 			printf("%8s %7d %10d %10d %9d    %4.2f %10d  %10d   %10d<BR>\n",
