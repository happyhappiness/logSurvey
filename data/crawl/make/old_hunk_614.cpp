      definition[idx++] = '\n';
    }

  /* No `endef'!!  */
  fatal (&defstart, _("missing `endef', unterminated `define'"));
}

/* Interpret conditional commands "ifdef", "ifndef", "ifeq",
