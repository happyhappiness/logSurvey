      }
      gss_release_buffer(&min_stat, &status_string);
    }
    if (debug)
      fprintf(stderr, "%s| %s: %s failed: %s\n", LogTime(), PROGRAM, function, buf);
    fprintf(stdout, "NA %s failed: %s\n",function, buf);
    if (loging)
      fprintf(stderr, "%s| %s: User not authenticated\n", LogTime(), PROGRAM);
    return(1);
  }
  return(0);
}

int main(int argc, char * const argv[])
{
  char buf[MAX_AUTHTOKEN_LEN];
  char *c;
  int length=0;
  static int err=0;
  int opt, rc, debug=0, loging=0;
  OM_uint32 ret_flags=0, spnego_flag=0;
  char *service_name=(char *)"HTTP",*host_name=NULL;
  char *token = NULL;
