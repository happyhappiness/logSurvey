 	case RESUME_ABORT:
 		am_abort(&state);
 		break;
+	case RESUME_SHOW_PATCH:
+		ret = show_patch(&state);
+		break;
 	default:
 		die("BUG: invalid resume value");
 	}
 
 	am_state_release(&state);
 
-	return 0;
+	return ret;
 }
