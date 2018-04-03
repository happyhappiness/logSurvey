    return aHashEntry->user();
}

void *
AuthUserRequestState::operator new (size_t)
{
    fatal ("unusable\n");
}

void
AuthUserRequestState::operator delete (void *)
{
    fatal ("unusable\n");
}
