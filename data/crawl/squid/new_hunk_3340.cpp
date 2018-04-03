    debugs(29, 5, "NegotiateUser::~NegotiateUser: doing nothing to clearNegotiate scheme data for '" << this << "'");
}

int32_t
NegotiateUser::ttl() const
{
    return -1; // Negotiate cannot be cached.
}

static void
