#pragma once
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include "str.h"

typedef struct {
    pthread_mutex_t mtx;
    FILE *file;
    size_t pos;  // next opening at file offset index[pos]
    long *index;  // vector of file offsets
} Openings;

Openings openings_new(const char *fileName, bool random, int threadId);
void openings_delete(Openings *openings, int threadId);

void openings_next(Openings *o, str_t *fen, int threadId);
