		state = sDOC;
	    } else {
		printf("Error on line %d\n", linenum);
		printf("--> %d bytes, %s\n", strlen(buff), buff);
		exit(1);
	    }
	    break;