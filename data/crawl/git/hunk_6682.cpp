 			die("Cannot setup tracking information; starting point is not a branch.");
 		break;
 	case 1:
-		/* Unique completion -- good */
+		/* Unique completion -- good, only if it is a real ref */
+		if (track == BRANCH_TRACK_EXPLICIT && !strcmp(real_ref, "HEAD"))
+			die("Cannot setup tracking information; starting point is not a branch.");
 		break;
 	default:
 		die("Ambiguous object name: '%s'.", start_name);
