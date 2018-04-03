	}
	printf("commit %s\n", local_ref);
	printf("mark :%"PRIu32"\n", revision);
	printf("committer %s <%s@%s> %"PRItime" +0000\n",
		   *author ? author : "nobody",
		   *author ? author : "nobody",
		   *uuid ? uuid : "local", timestamp);