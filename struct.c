#include "struct.h"

/**
 * @brief 트리에 노드를 삽입한다.
 * 중복되는 데이터가 있을 경우 삽입하지 않는다.
 *
 * @param tree
 * @param data
 * @return bool - 삽입 성공 시 true, 실패 시 false
 */
bool tree_insert(tree_t **tree, int data)
{
	if_null_return(tree, false);

	// 새 노드 생성
	tree_t *newnode = (tree_t *)xcalloc(sizeof(*newnode));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	// 트리가 비어있는 경우 최상위 노드에 값을 넣고 종료
	if (is_null(*tree)) {
		*tree = newnode;
		return true;
	}

	tree_t *curr = *tree;
	tree_t *parent = NULL;

	// 삽입 위치 찾기
	while (is_not_null(curr)) {
		parent = curr;
		// 현재 노드의 데이터보다 작은 경우 왼쪽으로 이동
		if (data < curr->data) {
			curr = curr->left;
			// 현재 노드의 데이터보다 클 경우 오른쪽으로 이동
		} else if (data > curr->data) {
			curr = curr->right;
			// 동일한 데이터가 있을 경우 삽입하지 않도록 이진 탐색 트리를 만들었다.
		} else {
			// 삽입에 실패하였으므로 false를 반환한다.
			xfree(newnode);
			return false;
		}
	}

	// 찾은 위치에 새 노드 삽입
	if (data < parent->data) {
		parent->left = newnode;
	} else {
		parent->right = newnode;
	}

	return true;
}

// 만들어 둔 BFS 알고리즘을 이용하여 트리를 모두 삭제하는 알고리즘
void tree_destroy(tree_t **tree)
{
	if_null_return(tree, );
	if_null_return(*tree, );

	queue_t queue = { 0, };

	queue_insert(&queue, *tree);
	while (queue_empty(&queue) is false) {
		tree_t *node = queue_pop(&queue);

		if (is_not_null(node->left)) {
			queue_insert(&queue, node->left);
		}
		if (is_not_null(node->right)) {
			queue_insert(&queue, node->right);
		}
		memset(node, 0, sizeof(*node));
		xfree(node);
	}
	*tree = NULL;
}


/**
 * @brief 큐를 이용하여 너비우선탐색을 진행한다.
 *
 * @param tree - 너비우선탐색을 진행할 tree 포인터
 */
void BFS(tree_t *tree)
{
	// 트리 포인터가 NULL이면 트리는 비어있는 것
	if_null_cmd_return(tree, , printf("tree is empty\n"));

	// 너비우산탐색을 위한 큐 생성
	queue_t queue = { 0, };

	// 최상위 노드를 큐에 삽입
	queue_insert(&queue, tree);

	// 큐가 비어있으면 트리를 모두 순회한 것으로 간주
	while (queue_empty(&queue) is false) {
		// 큐에서 노드를 하나 꺼내 노드의 값을 출력한다.
		tree_t *node = queue_pop(&queue);

		printf("%d, ", node->data);

		// 왼쪽, 오른쪽 노드가 비어있지 않으면 큐에 삽입한다.
		if (is_not_null(node->left)) {
			queue_insert(&queue, node->left);
		}
		if (is_not_null(node->right)) {
			queue_insert(&queue, node->right);
		}
	}

	printf("\b\b  \n");
}


/**
 * @brief 큐 삽입 함수
 *
 * @param queue
 * @param data - 저장할 tree 포인터
 */
void queue_insert(queue_t *queue, tree_t *data)
{
	if_null_return(queue, );

	// 새 노드 생성
	quenode_t *newnode = (quenode_t *)xcalloc(sizeof(*newnode));
	newnode->data = data;
	newnode->next = NULL;

	// 큐가 비어있는 경우
	if (queue_empty(queue)) {
		queue->front = newnode;
		queue->rear = newnode;
		++queue->cnt;
		return;
	}

	// 큐가 비어있지 않은 경우
	queue->rear->next = newnode;
	queue->rear = newnode;
	++queue->cnt;
}

/**
 * @brief 큐의 front를 제거하면서 값을 반환한다.
 *
 * @param queue
 * @return tree_t*
 */
tree_t* queue_pop(queue_t *queue)
{
	if_null_return(queue, NULL);
	if_true_return(queue_empty(queue), NULL);

	quenode_t *tmp = queue->front;
	tree_t *treenode = tmp->data;
	queue->front = queue->front->next;
	if (is_null(queue->front)) {
		queue->rear = NULL;
	}
	xfree(tmp);
	--queue->cnt;

	return treenode;
}

/**
 * @brief 큐의 모든 데이터를 제거한다.
 *
 * @param queue
 */
void queue_destroy(queue_t *queue)
{
	if_null_return(queue, );
	while (is_not_null(queue->front)) {
		quenode_t *tmp = queue->front;
		queue->front = queue->front->next;
		xfree(tmp);
	}
	memset(queue, 0, sizeof(*queue));
}

