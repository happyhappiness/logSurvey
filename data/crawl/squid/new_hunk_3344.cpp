    debugs(29, 5, "NTLMUser::~NTLMUser: doing nothing to clearNTLM scheme data for '" << this << "'");
}

int32_t
NTLMUser::ttl() const
{
    return -1; // NTLM credentials cannot be cached.
}

static void
