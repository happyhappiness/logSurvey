    }
}

static void
parse_port_option(AnyP::PortCfgPointer &s, char *token)
{
    /* modes first */

    if (strcmp(token, "accel") == 0) {
        if (s->flags.isIntercepted()) {
            debugs(3, DBG_CRITICAL, "FATAL: http(s)_port: Accelerator mode requires its own port. It cannot be shared with other modes.");
            self_destruct();
        }
        s->flags.accelSurrogate = true;
        s->vhost = true;
    } else if (strcmp(token, "transparent") == 0 || strcmp(token, "intercept") == 0) {
        if (s->flags.accelSurrogate || s->flags.tproxyIntercept) {
            debugs(3, DBG_CRITICAL, "FATAL: http(s)_port: Intercept mode requires its own interception port. It cannot be shared with other modes.");
            self_destruct();
        }
        s->flags.natIntercept = true;
