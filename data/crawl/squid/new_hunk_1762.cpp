        }

        /* we're finished, release the helper */
        auth_user_request->user()->username(userNote);
        auth_user_request->denyMessage("Login successful");
        safe_free(lm_request->server_blob);
        lm_request->server_blob = xstrdup(tokenNote);
        lm_request->releaseAuthServer();

        /* connection is authenticated */
