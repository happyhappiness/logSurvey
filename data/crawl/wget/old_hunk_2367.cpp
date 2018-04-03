          if (res_retrieve_file (url, &rfile))
            {
              specs = res_parse_from_file (rfile);
              xfree (rfile);
            }
          else
