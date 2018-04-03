{
  bool value;

  switch (cmd_boolean_internal (com, val, place))
    {
    case 0:
      value = false;
      break;

    case 1:
      value = true;
      break;

    default:
      {
        fprintf (stderr,
                 _("%s: %s: Invalid boolean %s; use `on' or `off'.\n"),
                 exec_name, com, quote (val));
        return false;
      }
    }
  *(bool *) place = value;
  return true;
}

/* Store the check_cert value from VAL to PLACE.  COM is ignored,
   except for error messages.  */
static bool
cmd_check_cert (const char *com, const char *val, void *place)
{
  int value;

  switch (cmd_boolean_internal (com, val, place))
    {
    case 0:
      value = CHECK_CERT_OFF;
      break;

    case 1:
      value = CHECK_CERT_ON;
      break;

    default:
      {
        if (!c_strcasecmp (val, "quiet"))
          value = CHECK_CERT_QUIET;
        else
          {
            fprintf (stderr,
                     _("%s: %s: Invalid %s; use `on', `off' or `quiet'.\n"),
                     exec_name, com, quote (val));
            return false;
          }
      }
    }
  *(int *) place = value;
  return true;
}

/* Set the non-negative integer value from VAL to PLACE.  With
   incorrect specification, the number remains unchanged.  */
static bool
