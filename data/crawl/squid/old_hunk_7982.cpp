     char *url1, *url2;
{
    if (!url1 || !url2)
	death();
    return (strcmp(url1, url2));
}

