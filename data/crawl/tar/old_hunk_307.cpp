	  break;							\
									\
	case LONGINT_INVALID_SUFFIX_CHAR:				\
	  error ((Exit_code), 0, "invalid character following %s `%s'",	\
		 (Argument_type_string), (Str));			\
	  break;							\
									\
