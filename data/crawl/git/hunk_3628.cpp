 		break;
 
 	case PUSH_DEFAULT_CURRENT:
+		branch = branch_get(NULL);
+		if (!branch)
+			die(_(message_detached_head_die), remote->name);
 		add_refspec("HEAD");
 		break;
 