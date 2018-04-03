      }
#else
    else
      fatal("%s (line %d) Invalid shell context (!unixy && !batch_mode_shell)\n",
            __FILE__, __LINE__);
#endif
  }
