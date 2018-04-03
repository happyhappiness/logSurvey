  int prefer_family = prefer_ipv4;
  int ok = decode_string (val, choices, countof (choices), &prefer_family);
  if (!ok)
    fprintf (stderr, _("%s: %s: Invalid value %s.\n"), exec_name, com, quote (val));
  opt.prefer_family = prefer_family;
  return ok;
}
