     "faulty" attempt is always preceded with all-faulty addresses,
     and this is how Wget uses it.  */
  assert (index == al->faulty);
  if (index != al->faulty)
    {
      logprintf (LOG_ALWAYS, "index: %d\nal->faulty: %d\n", index, al->faulty);
      logprintf (LOG_ALWAYS, _("Error in handling the address list.\n"));
      logprintf (LOG_ALWAYS, _("Please report this issue to bug-wget@gnu.org\n"));
      abort();
    }

  ++al->faulty;
  if (al->faulty >= al->count)
