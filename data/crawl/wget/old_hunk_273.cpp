      user = NULL; /* force freeing mem and return */
    }

  if (!realm || !nonce || !user || !passwd || !path || !method)
    {
      xfree_null (realm);
      xfree_null (opaque);
      xfree_null (nonce);
      xfree_null (qop);
      return NULL;
    }

