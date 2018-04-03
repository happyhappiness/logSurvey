int
urlcmp(const void *url1, const void *url2)
{
    assert(url1 && url2);
    return (strcmp(url1, url2));
}
