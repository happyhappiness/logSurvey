		          cio->callback_data);
			break;
		    case COMM_CB_WRITE:
			cio->c.w_callback(cio->fd, cio->buf, cio->retval, cio->errcode, cio->xerrno,
			  cio->callback_data);
		        break;
		    case COMM_CB_ACCEPT:
                        cio->c.a_callback(cio->fd, cio->newfd, &cio->me, &cio->pn, cio->errcode,
