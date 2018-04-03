#endif
      else if (is_dir)
#ifdef VMS
        {
          if (vms_report_unix_paths)
            o = variable_buffer_output (o, "./", 2);
          else
            o = variable_buffer_output (o, "[]", 2);
        }
#else
#ifndef _AMIGA
      o = variable_buffer_output (o, "./", 2);
