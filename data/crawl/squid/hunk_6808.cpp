 		usage();
 	    break;
 	case 'm':
+	    if (optarg) {
 #if MALLOC_DBG
-	    malloc_debug_level = atoi(optarg);
-	    /* NOTREACHED */
-	    break;
+		malloc_debug_level = atoi(optarg);
+		/* NOTREACHED */
+		break;
 #else
-	    fatal("Need to add -DMALLOC_DBG when compiling to use -m option");
-	    /* NOTREACHED */
+		fatal("Need to add -DMALLOC_DBG when compiling to use -mX option");
+		/* NOTREACHED */
+#endif
+	    } else {
+#if XMALLOC_TRACE
+		xmalloc_trace = !xmalloc_trace;
+#else
+		fatal("Need to configure --enable-xmalloc-debug-trace to use -m option");
 #endif
+	    }
 	case 's':
 	    opt_syslog_enable = 1;
 	    break;
