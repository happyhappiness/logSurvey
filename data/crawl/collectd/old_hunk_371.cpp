
{NUMBER}		{yylval.number = strtod (yytext, NULL); return (NUMBER);}

{QUOTED_STRING}		{yylval.string = yytext; return (QUOTED_STRING);}
{UNQUOTED_STRING}	{yylval.string = yytext; return (UNQUOTED_STRING);}
%%
