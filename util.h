#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define is ==
#define isnot !=
#define not !
#define or ||
#define and &&

#define true 	1
#define false 	0
#define bool 	unsigned char

#define is_null(_ptr) ((_ptr) == NULL)
#define is_not_null(_ptr) ((_ptr) != NULL)
#define is_true(_ptr) ((_ptr) == true)
#define is_flase(_ptr) ((_ptr) == false)

#define if_null_return(_ptr, _return) if ((_ptr) == NULL) { return _return; }
#define if_null_cmd_return(_ptr, _return, _cmd) if ((_ptr) == NULL) { _cmd; return _return; }
#define if_true_return(_ptr, _return) if ((_ptr) == true) { return _return; }

#define xfree(_ptr) if((_ptr) != NULL) { free((_ptr)); (_ptr) = NULL; }




void* xalloc(size_t size);
void* xcalloc(size_t size);
void* xrealloc(void *ptr, size_t size);


#endif /* _UTIL_H_ */