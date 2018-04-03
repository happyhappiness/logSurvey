      free(s2);
  }
  if (slow_flag)
#endif /* WIN32 */
    goto slow;

  if (ifs != 0)
    for (ap = ifs; *ap != '\0'; ++ap)
