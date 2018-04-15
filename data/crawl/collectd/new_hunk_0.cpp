block:
	block_begin statement_list block_end
	{
	 if (strcmp($1.key, $3) != 0)
	 {
		printf("block_begin = %s; block_end = %s;\n", $1.key, $3);
		yyerror("block not closed");
		YYERROR;
	 }
