 
 #ifndef NO_IPV6
 
+static const char *ai_name(const struct addrinfo *ai)
+{
+	static char addr[INET_ADDRSTRLEN];
+	if ( AF_INET == ai->ai_family ) {
+		struct sockaddr_in *in;
+		in = (struct sockaddr_in *)ai->ai_addr;
+		inet_ntop(ai->ai_family, &in->sin_addr, addr, sizeof(addr));
+	} else if ( AF_INET6 == ai->ai_family ) {
+		struct sockaddr_in6 *in;
+		in = (struct sockaddr_in6 *)ai->ai_addr;
+		inet_ntop(ai->ai_family, &in->sin6_addr, addr, sizeof(addr));
+	} else {
+		strcpy(addr, "(unknown)");
+	}
+	return addr;
+}
+
 /*
  * Returns a connected socket() fd, or else die()s.
  */
