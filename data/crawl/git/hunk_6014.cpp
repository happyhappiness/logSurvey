 		imap_info("Connecting to %s:%hu... ", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
 		if (connect(s, (struct sockaddr *)&addr, sizeof(addr))) {
 			close(s);
+			s = -1;
 			perror("connect");
+		}
+#endif
+		if (s < 0) {
+			fputs("Error: unable to connect to server.\n", stderr);
 			goto bail;
 		}
 