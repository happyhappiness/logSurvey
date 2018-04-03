	break;
      }

# ifdef __EMX__
    case EINVAL:
      /* this nasty error was driving me nuts :-( */
      error (NILF, _("spawnvpe: environment space might be exhausted"));
      /* FALLTHROUGH */
# endif

    default:
      perror_with_name ("execvp: ", argv[0]);
      break;
    }

# ifdef __EMX__
  return pid;
# else
  _exit (127);
# endif
#endif /* !WINDOWS32 */
#endif /* !VMS */
}
