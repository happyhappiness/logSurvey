		else
			free_arg_item(arg_tok);
		break;
	default:
		die("BUG: trailer.c: unhandled value %d",
		    arg_tok->conf.if_exists);
	}
}

