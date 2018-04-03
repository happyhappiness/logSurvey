 		case BRANCH_TRACK_OVERRIDE:
 			break;
 		default:
-			return 1;
+			return;
 		}
 
 	if (tracking.matches > 1)
-		return error(_("Not tracking: ambiguous information for ref %s"),
-				orig_ref);
+		die(_("Not tracking: ambiguous information for ref %s"),
+		    orig_ref);
 
-	install_branch_config(config_flags, new_ref, tracking.remote,
-			      tracking.src ? tracking.src : orig_ref);
+	if (install_branch_config(config_flags, new_ref, tracking.remote,
+			      tracking.src ? tracking.src : orig_ref) < 0)
+		exit(-1);
 
 	free(tracking.src);
-	return 0;
 }
 
 int read_branch_desc(struct strbuf *buf, const char *branch_name)
