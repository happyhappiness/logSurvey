 	    if (parse_menu)
 		fputs(munge_menu_line(buf, req), stdout);
 	    else
-		fputs(buf, stdout);
+		fputs(munge_other_line(buf, req), stdout);
 	    break;
 	case isForward:
 	    /* forward: no modifications allowed */
