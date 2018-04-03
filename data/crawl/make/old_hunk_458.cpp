	  /* Restore conditional state.  */
	  restore_conditionals (save);

          goto rule_complete;
	}

      /* This line starts with a tab but was not caught above because there
         was no preceding target, and the line might have been usable as a
         variable definition.  But now we know it is definitely lossage.  */
