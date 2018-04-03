 	    break;
 	default:
 	    fprintf(stderr, "unknown option: -%c. Exiting\n", opt);
+	    usage();
 	    had_error = 1;
 	}
     }
