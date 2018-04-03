 #endif
 	    }
 	case 's':
+#if HAVE_SYSLOG
 	    opt_syslog_enable = 1;
 	    break;
+#else
+	    fatal("Logging to syslog not available on this platform");
+	    /* NOTREACHED */
+#endif
 	case 'u':
 	    icpPortNumOverride = atoi(optarg);
 	    if (icpPortNumOverride < 0)