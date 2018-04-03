	      target = parse_file_seq (&p2, ':', sizeof (struct nameseq), 1);
	      ++p2;
	      if (target == 0)
		fatal (&fileinfo, "missing target pattern");
	      else if (target->next != 0)
		fatal (&fileinfo, "multiple target patterns");
	      pattern = target->name;
	      pattern_percent = find_percent (pattern);
	      if (pattern_percent == 0)
		fatal (&fileinfo,
				"target pattern contains no `%%'");
              free((char *)target);
	    }
