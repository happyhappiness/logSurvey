       ci_copy->values[i].type = ci_orig->values[i].type;
       if (ci_copy->values[i].type == OCONFIG_TYPE_STRING)
       {
	 ci_copy->values[i].value.string
	   = strdup (ci_orig->values[i].value.string);
	 if (ci_copy->values[i].value.string == NULL)
	 {
	   fprintf (stderr, "strdup failed.\n");
	   oconfig_free (ci_copy);
	   return (NULL);
	 }
       }
       else /* ci_copy->values[i].type != OCONFIG_TYPE_STRING) */
       {
	 ci_copy->values[i].value = ci_orig->values[i].value;
       }
    }
  } /* }}} if (ci_orig->values_num > 0) */