	 * check for this switch for backward compatibility.
	 */
	int convert_varargs = 1;

	if ( argc > 1 && argv[1][0] == '-' )
	  {	if ( !strcmp(argv[1], "--varargs") )
		  {	convert_varargs = 1;
			argc--;
			argv++;
		  }
		else
		  {	fprintf(stderr, "Unrecognized switch: %s\n", argv[1]);
			exit(1);
		  }
	  }
	if (argc < 2 || argc > 3)
	   {
		printf("Usage: ansi2knr input_file [output_file]\n");
			exit(1);
		   }
	in = fopen(argv[1], "r");
	if ( in == NULL )
	  {
	    fprintf(stderr, "Cannot open input file %s\n", argv[1]);
		exit(1);
	   }
 	if (argc == 3)
 	  {
 	    out = fopen(argv[2], "w");
 	    if ( out == NULL )
 	      {
 		fprintf(stderr, "Cannot open output file %s\n", argv[2]);
 		exit(1);
 	      }
 	  }
 	else
 	  {
 	    out = stdout;
 	  }
	fprintf(out, "#line 1 \"%s\"\n", argv[1]);
	buf = malloc(bufsize);
	line = buf;
	while ( fgets(line, (unsigned)(buf + bufsize - line), in) != NULL )
	   {
