		    else
			printf(" %20s %10d %s\n", s1, d1, s2 + 2);
		    break;
		case RESPT:
		    p_state = 1;
		    memset(s1, '\0', 255);
		    d1 = 0;
		    sscanf(reserve, "%s %d", s1, &d1);
		    if (hasTables)
			printf("<tr><td><B>%s</B><td>%d\n", s1, d1);
		    else
			printf(" %20s %10d\n", s1, d1);
		    break;
		case STATS_U:
		    p_state = 1;
		    sscanf(reserve, "%s %d %d %d %d %f %d %d %d",
