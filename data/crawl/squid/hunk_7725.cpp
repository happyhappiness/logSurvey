 	    printf("$ipcount %d\n", addr_count);
 	    for (i = 0; i < addr_count; i++) {
 		struct in_addr addr;
-		memcpy((char *) &addr, result->h_addr_list[i], result->h_length);
+		xmemcpy((char *) &addr, result->h_addr_list[i], result->h_length);
 		printf("%s\n", inet_ntoa(addr));
 	    }
 
