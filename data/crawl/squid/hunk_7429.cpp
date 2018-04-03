 	    if (p_state == 3) {
 		int sn;
 		switch (op) {
-		case INFO:
 		case CACHED:
+		    p_state = 1;
+		    for (s = reserve; *s; s++)
+			switch (*s) {
+			case '<': printf("&lt;");  break;
+			case '&': printf("&amp;"); break;
+			default:  putchar(*s);     break;
+			}
+		    break;
+		case INFO:
 		case SERVER:
 		case CLIENTS:
 		case LOG:
