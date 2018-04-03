              got_name = true;
              restart_loop = true;
            }

          got_head = true;    /* no more time-stamping */
          *dt &= ~HEAD_ONLY;
