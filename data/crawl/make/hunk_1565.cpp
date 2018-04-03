       fputs ("Options:\n", stderr);
       for (cs = switches; cs->c != '\0'; ++cs)
 	{
-	  char buf[1024], arg[50];
+	  char buf[1024], arg[50], *p;
 
 	  if (cs->description[0] == '-')
 	    continue;
