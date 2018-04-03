  FreeConsole ();
}

void
fork_to_background (void)
{
  ws_hangup ("fork");
}

static BOOL WINAPI
