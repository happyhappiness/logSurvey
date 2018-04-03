
/* to be split into separate files in the future */

MemPool *acl_user_data::Pool(NULL);
void *
acl_user_data::operator new (size_t byteCount)
{
    /* derived classes with different sizes must implement their own new */
    assert (byteCount == sizeof (acl_user_data));
    if (!Pool)
	Pool = memPoolCreate("acl_user_data", sizeof (acl_user_data));
    return memPoolAlloc(Pool);
}

void
acl_user_data::operator delete (void *address)
{
    memPoolFree (Pool, address);
}

void
acl_user_data::deleteSelf() const
{
    delete this;
}

#if USE_SSL
MemPool *acl_cert_data::Pool(NULL);
void *
acl_cert_data::operator new (size_t byteCount)
{
    /* derived classes with different sizes must implement their own new */
    assert (byteCount == sizeof (acl_cert_data));
    if (!Pool)
	Pool = memPoolCreate("acl_cert_data", sizeof (acl_cert_data));
    return memPoolAlloc(Pool);
}

void
acl_cert_data::operator delete (void *address)
{
    memPoolFree (Pool, address);
}

void
acl_cert_data::deleteSelf() const
{
    delete this;
}
#endif /* USE_SSL */
