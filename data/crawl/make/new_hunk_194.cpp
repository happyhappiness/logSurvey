      }
#else
    else
      fatal (NILF, CSTRLEN (__FILE__) + INTSTR_LENGTH,
             _("%s (line %d) Bad shell context (!unixy && !batch_mode_shell)\n"),
            __FILE__, __LINE__);
#endif

