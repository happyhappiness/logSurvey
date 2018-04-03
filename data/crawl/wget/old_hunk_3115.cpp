  for (i = 0; i < countof (help); i++)
    fputs (_(help[i]), stdout);

#ifdef WINDOWS
  ws_help (exec_name);
#endif
  exit (0);
}

