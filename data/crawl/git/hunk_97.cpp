 		case 0:
 			break;
 		case -1:
-			die_errno("fork failed");
+			die_errno(_("fork failed"));
 		default:
 			exit(0);
 	}
 	if (setsid() == -1)
-		die_errno("setsid failed");
+		die_errno(_("setsid failed"));
 	close(0);
 	close(1);
 	close(2);
