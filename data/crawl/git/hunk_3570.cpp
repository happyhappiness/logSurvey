 		break;
 
 	case PUSH_DEFAULT_SIMPLE:
-		setup_push_upstream(remote, 1);
+		if (triangular)
+			setup_push_current(remote, branch);
+		else
+			setup_push_upstream(remote, branch, triangular);
 		break;
 
 	case PUSH_DEFAULT_UPSTREAM:
-		setup_push_upstream(remote, 0);
+		setup_push_upstream(remote, branch, triangular);
 		break;
 
 	case PUSH_DEFAULT_CURRENT:
-		branch = branch_get(NULL);
-		if (!branch)
-			die(_(message_detached_head_die), remote->name);
-		add_refspec(branch->name);
+		setup_push_current(remote, branch);
 		break;
 
 	case PUSH_DEFAULT_NOTHING: