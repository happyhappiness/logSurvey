      free ((char *) child->environment);
    }

  /* If this child has a token it hasn't relinquished, give it up now.
     This can happen if the job completes immediately, mainly because
     all the command lines evaluated to empty strings.  */
  free_job_token(child);

  free ((char *) child);
}
