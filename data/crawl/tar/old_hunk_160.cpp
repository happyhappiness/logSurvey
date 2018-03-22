
#else /* not DEVICE_PREFIX */

      argp_error (state, 
		  _("Options `-[0-7][lmh]' not supported by *this* tar"));
      
#endif /* not DEVICE_PREFIX */
      
    case '?':
      state->flags |= ARGP_NO_EXIT;
      argp_state_help (state, state->out_stream,
