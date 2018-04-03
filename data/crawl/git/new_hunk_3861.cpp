			} while (len);
			continue;
		case 1:
			write_or_die(out, buf + pf+1, len);
			continue;
		default:
			fprintf(stderr, "%s: protocol error: bad band #%d\n",
