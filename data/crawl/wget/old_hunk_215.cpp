        {
          *out = s;
          *(s + len - outlen - done) = '\0';
          return true;
        }

