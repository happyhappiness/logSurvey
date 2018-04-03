     and we set the -p, -i and -e switches.  Doesn't seem quite right.  */
  decode_env_switches (STRING_SIZE_TUPLE ("MFLAGS"));
#endif

  decode_switches (argc, argv, 0);

#ifdef WINDOWS32
  if (suspend_flag) {
        fprintf(stderr, "%s (pid = %ld)\n", argv[0], GetCurrentProcessId());
