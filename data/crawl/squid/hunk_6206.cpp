 		 * RES_INIT is wrong.  The resolver code sets RES_INIT
 		 * after calling res_init().  When we change the _res
 		 * structure and set RES_INIT, some internal resolver
-		 * structures get confused.		-DW 2.1.p1
+		 * structures get confused.             -DW 2.1.p1
 		 */
 #if SEEMS_WRONG
 		_res.options |= RES_INIT;
 #endif
 		opt_s = 1;
 	    } else if (_res.nscount == MAXNS) {
-	        fprintf(stderr, "Too many -s options, only %d are allowed\n",	
-			MAXNS);
+		fprintf(stderr, "Too many -s options, only %d are allowed\n",
+		    MAXNS);
 		break;
 	    }
 #if HAVE_RES_NSADDR_LIST
-	    _res.nsaddr_list[_res.nscount]=_res.nsaddr_list[0];
+	    _res.nsaddr_list[_res.nscount] = _res.nsaddr_list[0];
 	    safe_inet_addr(optarg, &_res.nsaddr_list[_res.nscount++].sin_addr);
 #elif HAVE_RES_NS_LIST
-	    _res.ns_list[_res.nscount]=_res.ns_list[0];
+	    _res.ns_list[_res.nscount] = _res.ns_list[0];
 	    safe_inet_addr(optarg, &_res.ns_list[_res.nscount++].addr.sin_addr);
 #else /* Unknown NS list format */
 	    fprintf(stderr, "-s is not supported on this resolver\n");
