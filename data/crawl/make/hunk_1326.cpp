 	  }
 
 	case GLOB_NOSPACE:
-	  fatal ("virtual memory exhausted");
+	  fatal (NILF, "virtual memory exhausted");
 	  break;
 
 	default:
