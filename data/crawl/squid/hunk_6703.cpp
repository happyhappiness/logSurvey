 	    }
 	    /* this is a way to pass HTTP status to the Web server */
 	    if (statusStr)
-		printf("Status: %d %s", status, statusStr);
+		printf("Status: %d %s\n", status, statusStr);
 	    break;
 	case isHeaders:
 	    /* forward header field */