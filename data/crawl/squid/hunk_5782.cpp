 	    load_balance = 1;
 	    break;
 	case 'f':
-	    failover_enabled = 1;
+	    fprintf(stderr,
+		"WARNING. The -f flag is DEPRECATED and always active.\n");
 	    break;
+#ifdef NTLM_FAIL_OPEN
 	case 'l':
 	    last_ditch_enabled = 1;
 	    break;
+#endif
 	default:
 	    fprintf(stderr, "unknown option: -%c. Exiting\n", opt);
 	    usage();
