      exit (1);
    }

  if (opt.ask_passwd)
    {
      opt.passwd = prompt_for_password ();
