 		case 0:
 			break;
 		case -1:
-			die("fork failed: %s", strerror(errno));
+			die_errno("fork failed");
 		default:
 			exit(0);
 	}
 	if (setsid() == -1)
-		die("setsid failed: %s", strerror(errno));
+		die_errno("setsid failed");
 	close(0);
 	close(1);
 	close(2);
