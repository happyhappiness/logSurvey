        o = variable_buffer_output (o, p2, len);

#ifdef VMS
      if (vms_comma_separator)
        o = variable_buffer_output (o, ",", 1);
      else
#endif
        o = variable_buffer_output (o, " ", 1);

      doneany = 1;
    }

