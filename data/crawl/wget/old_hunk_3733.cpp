	  logputs (LOG_VERBOSE, tmpstr);
	  print_percentage (nrow * line_bytes + ndot * opt.dot_bytes + offs,
			    expected);
	}
      logputs (LOG_VERBOSE, "\n\n");
      return 0;
