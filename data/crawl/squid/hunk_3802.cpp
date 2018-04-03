 
         xmemcpy(ip, &R.sin_addr.s_addr, 4);
         hp = gethostbyaddr(ip, 4, AF_INET);
+        ipa = R.sin_addr;
         printf("==============================================================================\n");
         printf("Received from %s [%s]\n",
-               inet_ntoa(R.sin_addr),
+               ipa.NtoA(tmp,MAX_HOSTNAMELEN),
                (hp && hp->h_name) ? hp->h_name : "Unknown");
         fputs(buf, stdout);
         fflush(stdout);
