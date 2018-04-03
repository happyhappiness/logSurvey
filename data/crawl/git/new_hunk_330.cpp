			list_add_tail(&to_add->list, head);
		else
			list_add(&to_add->list, head);
		break;
	default:
		die("BUG: trailer.c: unhandled value %d",
		    arg_tok->conf.if_missing);
	}
}

