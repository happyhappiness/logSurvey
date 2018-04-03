		printf("%d answers\n", n);
		for (i = 0; i < n; i++) {
		    if (answers[i].type == RFC1035_TYPE_A) {
			struct in_addr a;
			memcpy(&a, answers[i].rdata, 4);
			printf("A\t%d\t%s\n", answers[i].ttl, inet_ntoa(a));
		    } else if (answers[i].type == RFC1035_TYPE_PTR) {
