 		theInIcpConnection);
 
 	    if ((addr = Config.Addrs.udp_outgoing).s_addr != INADDR_NONE) {
-		theOutIcpConnection = comm_open(COMM_NONBLOCKING | COMM_DGRAM,
+		theOutIcpConnection = comm_open(SOCK_DGRAM,
+			0,
 		    addr,
 		    port,
+			COMM_NONBLOCKING,
 		    "ICP Port");
 		if (theOutIcpConnection < 0)
 		    fatal("Cannot open Outgoing ICP Port");
