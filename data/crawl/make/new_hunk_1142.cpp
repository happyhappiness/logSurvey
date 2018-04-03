  print_vpath_data_base ();

  when = time ((time_t *) 0);
  printf (_("\n# Finished Make data base on %s\n"), ctime (&when));
}

/* Exit with STATUS, cleaning up as necessary.  */
