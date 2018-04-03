	break;
      }

    default:
      perror_with_name ("execvp: ", argv[0]);
      break;
    }

  _exit (127);
#endif /* !WINDOWS32 */
#endif /* !VMS */
}
