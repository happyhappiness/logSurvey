			printf("Value not found for \"%s\"\n", argv[2]);
			goto exit1;
		}
	}

	die("%s: Please check the syntax and the function name", argv[0]);
