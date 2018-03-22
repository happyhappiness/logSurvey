    }

  if (chmod (file_name, mode) != 0)
    chmod_error_details (file_name, mode);
}

/* Restore stat attributes (owner, group, mode and times) for
