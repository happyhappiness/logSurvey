 	      target = parse_file_seq (&p2, ':', sizeof (struct nameseq), 1);
 	      ++p2;
 	      if (target == 0)
-		makefile_fatal (filename, lineno, "missing target pattern");
+		fatal (&fileinfo, "missing target pattern");
 	      else if (target->next != 0)
-		makefile_fatal (filename, lineno, "multiple target patterns");
+		fatal (&fileinfo, "multiple target patterns");
 	      pattern = target->name;
 	      pattern_percent = find_percent (pattern);
 	      if (pattern_percent == 0)
-		makefile_fatal (filename, lineno,
+		fatal (&fileinfo,
 				"target pattern contains no `%%'");
               free((char *)target);
 	    }
