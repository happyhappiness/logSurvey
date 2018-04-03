#endif /* WINDOWS32 */
#endif

  /* The extra indirection through $(MAKE_COMMAND) is done
     for hysterical raisins.  */
  define_variable_cname ("MAKE_COMMAND", argv[0], o_default, 0);
