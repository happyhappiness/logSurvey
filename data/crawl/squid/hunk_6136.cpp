 	    unsigned short rid;
 	    int i;
 	    int n;
-	    struct in_addr addrs[10];
-	    time_t ttl = 0;
-	    char rname[RFC1035_MAXHOSTNAMESZ];
-	    n = rfc1035ARecordsUnpack(rbuf,
+	    rfc1035_rr *answers = NULL;
+	    n = rfc1035AnswersUnpack(rbuf,
 		rl,
-		addrs, 10,
-		rname, RFC1035_MAXHOSTNAMESZ,
-		&rid,
-		&ttl);
+		&answers,
+		&rid);
 	    if (rid != sid) {
 		printf("ERROR, ID mismatch (%#hx, %#hx)\n", sid, rid);
 	    } else if (n < 0) {
 		printf("ERROR %d\n", rfc1035_errno);
 	    } else {
-		printf("name\t%s, %d A records\n", rname, n);
-		printf("ttl\t%d\n", (int) ttl);
-		for (i = 0; i < n; i++)
-		    printf("addr %d\t%s\n", i, inet_ntoa(addrs[i]));
+		printf("%d answers\n", n);
+		for (i = 0; i < n; i++) {
+		    if (answers[i].type == RFC1035_TYPE_A) {
+			struct in_addr a;
+			memcpy(&a, answers[i].rdata, 4);
+			printf("A\t%d\t%s\n", answers[i].ttl, inet_ntoa(a));
+		    } else if (answers[i].type == RFC1035_TYPE_PTR) {
+			char ptr[128];
+			strncpy(ptr, answers[i].rdata, answers[i].rdlength);
+			printf("PTR\t%d\t%s\n", answers[i].ttl, ptr);
+		    } else {
+			fprintf(stderr, "can't print answer type %d\n",
+			    (int) answers[i].type);
+		    }
+		}
 	    }
 	}
     }