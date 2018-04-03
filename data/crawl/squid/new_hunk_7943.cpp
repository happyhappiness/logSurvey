#endif /* HAVE_MALLINFO */
}

int getHeapSize()
{
#if HAVE_MALLINFO