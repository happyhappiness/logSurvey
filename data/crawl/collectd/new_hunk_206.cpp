      if (status != 0)
        BAIL_OUT (status);
    }
    else {
      fprintf (stderr, "ERROR: flush: Unknown option `%s'.\n", key);
      BAIL_OUT (-1);
    }
  }

  if (plugins_num == 0) {