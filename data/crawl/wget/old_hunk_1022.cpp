    return true;

  logprintf (LOG_VERBOSE, "Conversion from %s to %s isn't supported\n",
             quote (opt.locale), quote("UTF-8"));
  locale2utf8 = NULL;
  return false;
}
