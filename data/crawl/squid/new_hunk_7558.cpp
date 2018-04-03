		    break;
		case STATS_U:
		    p_state = 1;
		    sn = sscanf(reserve, "%s %d %d %d %d %f %d %d %d",
			s1, &d1, &d2, &d3, &d4, &f1, &d5, &d6, &d7);
		    if (sn == 1) {
		        if (hasTables)
			    printf("<tr><td align=\"right\"><B>%s</B>", s1);
		        else
			    printf("%8s", s1);
			break;
		    }
		    if (hasTables)
			printf("<tr><td align=\"right\"><B>%s</B><td align=\"right\">%d<td align=\"right\">%d<td align=\"right\">%d<td align=\"right\">%d<td align=\"right\">%4.2f<td align=\"right\">%d<td align=\"right\">%d<td align=\"right\">%d",
			    s1, d1, d2, d3, d4, f1, d5, d6, d7);
