        diff = id - nodes[id]->id;
        skew += abs(diff);

#ifdef  HEAP_DEBUG_SKEW
        skewsq += diff * diff;
#ifdef  HEAP_DEBUG_ALL
        printf("%d\tKey = %f, diff = %d\n", id, nodes[id]->key, diff);
#endif /* HEAP_DEBUG */
#endif /* HEAP_DEBUG_SKEW */
