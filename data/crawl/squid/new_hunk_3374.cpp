            *arg++ = '\0';

        auth_user_request->denyMessage(arg);
        negotiate_request->user()->credentials(AuthUser::Failed);
        safe_free(negotiate_request->server_blob);
        negotiate_request->server_blob = xstrdup(blob);
        negotiate_request->releaseAuthServer();
