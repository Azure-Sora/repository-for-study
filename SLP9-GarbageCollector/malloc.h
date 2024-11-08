#ifndef __MALLOC_H_
#define __MALLOC_H_

/* $Id$ */

/*
 *
 */

#include <stdio.h>

extern int gc_init (void);
extern void *gc_malloc (size_t size);

/* Team information */
typedef struct {
    char *team;
    char *name1, *email1;
    char *name2, *email2;
} team_t;

extern team_t team;


#endif /* __MALLOC_H_ */

