 	  puts ("#  Successfully updated.");
 	  break;
 	case 1:
+	  assert (question_flag);
+	  puts ("#  Needs to be updated (-q is set).");
+	  break;
+	case 2:
 	  puts ("#  Failed to be updated.");
 	  break;
 	default:
