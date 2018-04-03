      if (is_notdir || p >= p2)
        {
#ifdef VMS
          o = variable_buffer_output (o, ",", 1);
#else
          o = variable_buffer_output (o, " ", 1);
#endif
          doneany = 1;
        }
    }
