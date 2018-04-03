    {
      if (!v->exp_count)
        /* Expanding V causes infinite recursion.  Lose.  */
        OS (fatal, *expanding_var,
            _("Recursive variable '%s' references itself (eventually)"),
            v->name);
      --v->exp_count;
    }

