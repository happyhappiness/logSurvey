 		theOutICPAddr = xaddr.sin_addr;
 	}
     }
-    if (Config.vizHack.port) {
-	vizSock = comm_open(SOCK_DGRAM,
-	    0,
-	    any_addr,
-	    0,
-	    COMM_NONBLOCKING,
-	    "VizHack Port");
-	if (vizSock < 0)
-	    fatal("Could not open Viz Socket");
-	mcastJoinVizSock();
-	memset(&Config.vizHack.S, '\0', sizeof(struct sockaddr_in));
-	Config.vizHack.S.sin_family = AF_INET;
-	Config.vizHack.S.sin_addr = Config.vizHack.addr;
-	Config.vizHack.S.sin_port = htons(Config.vizHack.port);
-    }
     clientdbInit();
     icmpOpen();
     netdbInit();
