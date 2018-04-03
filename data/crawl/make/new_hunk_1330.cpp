
      if (depth == 0 && keep_going_flag
	  && !just_print_flag && !question_flag)
	error (NILF, "Target `%s' not remade because of errors.", file->name);

      return dep_status;
    }
