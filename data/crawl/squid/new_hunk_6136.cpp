	    unsigned short rid;
	    int i;
	    int n;
	    rfc1035_rr *answers = NULL;
	    n = rfc1035AnswersUnpack(rbuf,
		rl,
		&answers,
		&rid);
	    if (rid != sid) {
		printf("ERROR, ID mismatch (%#hx, %#hx)\n", sid, rid);
	    } else if (n < 0) {
		printf("ERROR %d\n", rfc1035_errno);
	    } else {
		printf("%d answers\n", n);
		for (i = 0; i < n; i++) {
		    if (answers[i].type == RFC1035_TYPE_A) {
			struct in_addr a;
			memcpy(&a, answers[i].rdata, 4);
			printf("A\t%d\t%s\n", answers[i].ttl, inet_ntoa(a));
		    } else if (answers[i].type == RFC1035_TYPE_PTR) {
			char ptr[128];
			strncpy(ptr, answers[i].rdata, answers[i].rdlength);
			printf("PTR\t%d\t%s\n", answers[i].ttl, ptr);
		    } else {
			fprintf(stderr, "can't print answer type %d\n",
			    (int) answers[i].type);
		    }
		}
	    }
	}
    }