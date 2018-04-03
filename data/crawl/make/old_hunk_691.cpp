      expanding_var = &this_var;
    }

  if (v->expanding)
    {
      if (!v->exp_count)
        /* Expanding V causes infinite recursion.  Lose.  */
        fatal (this_var,
               _("Recursive variable `%s' references itself (eventually)"),
               v->name);
      --v->exp_count;
