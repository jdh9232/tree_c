#include "util.h"
#include "struct.h"

/*
 * Ununtu 22.04
 * Compiler : gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 * valgrind : valgrind-3.18.1
 */


void tree_BFS_1()
{
	// tree is empty

	tree_t *tree = NULL;
	BFS(tree);
	xfree(tree);
}

void tree_BFS_2()
{
	// 0, -10, 10

	tree_t *tree = NULL;
	tree_insert(&tree, 0);
	tree_insert(&tree, -10);
	tree_insert(&tree, 10);

	BFS(tree);
	tree_destroy(&tree);
	// 트리를 모두 제거하고 난 뒤에는 tree is empty 가 출력되어야 한다.
	BFS(tree);
}

void tree_BFS_3()
{
	// 트리의 최종 삽입 결과는 다음과 같다. (고정폭 폰트로 보는 것을 추천)
	//                      0
	//              -10          10
	//          -15    -5      7   13
	//        -20 -12    -2  5      15
	// 따라서 BFS의 결과는 다음과 같다.
	// 0, -10, 10, -15, -5, 7, 13, -20, -12, -2, 5, 15

	tree_t *tree = NULL;
	tree_insert(&tree, 0);
	tree_insert(&tree, -10);
	tree_insert(&tree, 10);
	tree_insert(&tree, -5);
	tree_insert(&tree, -2);
	tree_insert(&tree, -15);
	tree_insert(&tree, 7);
	tree_insert(&tree, 13);
	tree_insert(&tree, 5);
	tree_insert(&tree, 15);
	tree_insert(&tree, -12);
	tree_insert(&tree, -20);

	BFS(tree);
	tree_destroy(&tree);
	// 트리를 모두 제거하고 난 뒤에는 tree is empty 가 출력되어야 한다.
	BFS(tree);
}

int main()
{
	printf("tree_BFS_1 =============================================\n");
	tree_BFS_1();
	printf("tree_BFS_2 =============================================\n");
	tree_BFS_2();
	printf("tree_BFS_3 =============================================\n");
	tree_BFS_3();
	return 0;
}