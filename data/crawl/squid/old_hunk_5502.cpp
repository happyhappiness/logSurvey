		          cio->callback_data);
			break;
		    case COMM_CB_WRITE:
			fatal("write comm hasn't been implemented yet!");
		        break;
		    case COMM_CB_ACCEPT:
                        cio->c.a_callback(cio->fd, cio->newfd, &cio->me, &cio->pn, cio->errcode,
