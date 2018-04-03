      error (NILF, l + strlen (s) + strlen (dump),
             _("%s[%s] %s%s%s"), pre, f->name, s, dump, post);
    }
#endif /* VMS */

  OUTPUT_UNSET ();
}
