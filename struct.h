#ifndef _STRUCT_H
#define _STRUCT_H

#include "util.h"

// tree node
typedef struct _tree_t {
	struct _tree_t *left;
	struct _tree_t *right;

	int data;
} tree_t;

typedef struct _quenode_t {
	struct _quenode_t *next;
	tree_t *data;
} quenode_t;

// tree ptr을 저장하는 queue
typedef struct _queue_t {
	quenode_t 	*front;
	quenode_t 	*rear;

	int 		cnt;
} queue_t;


// tree 함수

bool tree_insert(tree_t **tree, int data);
void tree_destroy(tree_t **tree);
// https://velog.io/@inyong_pang/19%EA%B0%95-%EC%9D%B4%EC%A7%84-%ED%8A%B8%EB%A6%AC%EC%9D%98-%EB%84%93%EC%9D%B4-%EC%9A%B0%EC%84%A0-%EC%88%9C%ED%9A%8C-BFS-Breadth-First-Traversal
void BFS(tree_t *tree);

// queue 함수

/**
 * @brief 큐가 비어있는지 체크한다.
 * WARNING : queue 포인터에 대한 NULL 유효성 검증을 하지 않음.
 *
 * @param queue - 비어있는 큐 체크
 * @return bool
 */
static inline bool queue_empty(queue_t *queue)
{
	if_null_return(queue->front, true);
	if_true_return(queue->cnt is 0, true);

	return false;
}
void queue_insert(queue_t *queue, tree_t *data);
tree_t* queue_pop(queue_t *queue);
void queue_destroy(queue_t *queue);


#endif /* _STRUCT_H */