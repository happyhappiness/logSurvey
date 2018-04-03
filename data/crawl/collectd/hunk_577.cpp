 #else
 # define PRINT_VALUE(name, val) /**/
 #endif
+>>>>>>> .r733
 
+<<<<<<< .mine
+    tokptr = strtok(recvline,":");
+    while(tokptr != NULL) {
+      /* Look for Limit_Add */
+      if(strncmp("LINEV",tokptr,5) == 0) { 
+#ifdef APCMAIN
+	fprintf(stdout,"  Found LINEV.\n");
+#endif /* ifdef APCMAIN */
+	tokptr = strtok(NULL," \t");
+	if(tokptr == NULL) continue;
+	apcups_detail->linev = atof (tokptr);
+      }else if(strncmp("BATTV",tokptr,5) == 0) { 
+#ifdef APCMAIN
+	fprintf(stdout,"  Found BATTV.\n");
+#endif /* ifdef APCMAIN */
+	tokptr = strtok(NULL," \t");
+	if(tokptr == NULL) continue;
+	apcups_detail->battv = atof (tokptr);
+      }else if(strncmp("ITEMP",tokptr,5) == 0) { 
+#ifdef APCMAIN
+	fprintf(stdout,"  Found ITEMP.\n");
+#endif /* ifdef APCMAIN */
+	tokptr = strtok(NULL," \t");
+	if(tokptr == NULL) continue;
+	apcups_detail->itemp = atof (tokptr);
+      }else if(strncmp("LOADPCT",tokptr,7) == 0) { 
+#ifdef APCMAIN
+	fprintf(stdout,"  Found LOADPCT.\n");
+#endif /* ifdef APCMAIN */
+	tokptr = strtok(NULL," \t");
+	if(tokptr == NULL) continue;
+	apcups_detail->loadpct = atof (tokptr);
+      }else if(strncmp("BCHARGE",tokptr,7) == 0) { 
+#ifdef APCMAIN
+	fprintf(stdout,"  Found BCHARGE.\n");
+#endif /* ifdef APCMAIN */
+	tokptr = strtok(NULL," \t");
+	if(tokptr == NULL) continue;
+	apcups_detail->bcharge = atof (tokptr);
+      }else if(strncmp("OUTPUTV",tokptr,7) == 0) { 
+#ifdef APCMAIN
+	fprintf(stdout,"  Found OUTPUTV.\n");
+#endif /* ifdef APCMAIN */
+	tokptr = strtok(NULL," \t");
+	if(tokptr == NULL) continue;
+	apcups_detail->outputv = atof (tokptr);
+      }else if(strncmp("LINEFREQ",tokptr,8) == 0) { 
+#ifdef APCMAIN
+	fprintf(stdout,"  Found LINEFREQ.\n");
+#endif /* ifdef APCMAIN */
+	tokptr = strtok(NULL," \t");
+	if(tokptr == NULL) continue;
+	apcups_detail->linefreq = atof (tokptr);
+      }else if(strncmp("TIMELEFT",tokptr,8) == 0) { 
+#ifdef APCMAIN
+	fprintf(stdout,"  Found TIMELEFT.\n");
+#endif /* ifdef APCMAIN */
+	tokptr = strtok(NULL," \t");
+	if(tokptr == NULL) continue;
+	apcups_detail->timeleft = atof (tokptr);
+      } /* */
+      tokptr = strtok(NULL,":");
+    }
+  }
+=======
 	/* TODO: Keep the socket open, if possible */
 	if ((sockfd = net_open (host, NULL, port)) < 0)
 	{
 		syslog (LOG_ERR, "apcups plugin: Connecting to the apcupsd failed.");
 		return (-1);
 	}
+>>>>>>> .r733
 
+<<<<<<< .mine
+  if (n < 0) {
+    syslog(LOG_ERR, "apcups: Error recieving data: %s",
+	   net_errmsg);
+    net_errmsg = NULL;
+    return;
+  }
+  /* signal that we did in fact connect. */
+  apcups_detail->connected = 1;
+  
+  net_close(sockfd);
+=======
 	net_send (sockfd, "status", 6);
 
 	while ((n = net_recv (sockfd, recvline, sizeof (recvline))) > 0)
