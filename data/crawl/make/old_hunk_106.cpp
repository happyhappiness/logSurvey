#endif
      else if (is_dir)
#ifdef VMS
        o = variable_buffer_output (o, "[]", 2);
#else
#ifndef _AMIGA
      o = variable_buffer_output (o, "./", 2);