 		_res.options |= RES_INIT;
 		opt_s = 1;
 	    }
+#if HAVE_RES_NSADDR_LIST
 	    safe_inet_addr(optarg, &_res.nsaddr_list[_res.nscount++].sin_addr);
+#elif HAVE_RES_NS_LIST
+	    safe_inet_addr(optarg, &_res.ns_list[_res.nscount++].addr.sin_addr);
+#endif
+	    fprintf(stderr, "-s is not supported on this resolver\n");
 #else
 	    fprintf(stderr, "-s is not supported on this resolver\n");
 #endif /* HAVE_RES_INIT */
