 			      data->o->file, set, reset, ws);
 	} else if (line[0] == ' ') {
 		data->lineno++;
-		data->trailing_blanks_start = 0;
 	} else if (line[0] == '@') {
 		char *plus = strchr(line, '+');
 		if (plus)
 			data->lineno = strtol(plus, NULL, 10) - 1;
 		else
 			die("invalid diff");
-		data->trailing_blanks_start = 0;
 	}
 }
 
