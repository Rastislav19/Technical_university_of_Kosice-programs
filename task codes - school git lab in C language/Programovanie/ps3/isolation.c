#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct bubble {
	int number;
	struct bubble* left;
	struct bubble* right;
};

struct bubble* place_tree(struct bubble* root, int number);
struct bubble* place_bubble(int number);

bool are_equal(struct bubble* n, struct bubble* k); 

int main(){
	
    int n = 0, k = 0;
	//printf("number of prototypes and their layers: \n");
    scanf("%d %d", &n, &k);
	struct bubble* tree[n];
	int row = 0, col = 0;
	tree[row] = NULL;
    int number = 0;
    //printf("create 1. tree: \n");
    while (row != n){
        scanf("%d", &number);
		tree[row]  = place_tree(tree[row], number);
        col++;
		if (col == k){
			col = 0;
			row++;
			tree[row] = NULL;
            /*if(row != n){
                printf("create %d. tree: \n", row+1);    
            }
            */
        }
	}
  	
    int index = 0;
	int field[n];
	while (index != n){
		field[index] = 0;
		index++;
	}
 
	for (int idx = 0; idx < n; idx++){
		if (field[idx] == -1){
			continue;
		}
		for (int i = idx + 1; i < n; i++){
			if (are_equal(tree[idx], tree[i]) == true){
				field[i] = -1;
			}
		}
	}
	int j = 0, sum=0;
	while (j != n){
		if (field[j] == 0){
			sum++;
		}
		j++;
	}
    printf("%d\n", sum);
	return 0;
}

struct bubble* place_tree(struct bubble* root, int number){
	
    if (root == NULL){
		return place_bubble(number);
	}
	if (number < root->number){
		root->left = place_tree(root->left, number);
	}
	else if (number >= root->number){
		root->right = place_tree(root->right, number);
	}
	return root;
}

struct bubble* place_bubble(int number){
	struct bubble* new_bubble = (struct bubble*) calloc(1, sizeof(struct bubble));
	new_bubble->number = number;
	new_bubble->left = NULL;
	new_bubble->right = NULL;

	return new_bubble;
}

bool are_equal(struct bubble* n, struct bubble* k){
    if (n == NULL && k == NULL){ 
        return true;
    }
    if (n != NULL && k != NULL){
    	if (are_equal( n->left, k->left) && 
            are_equal( n->right, k->right) ){ 
            return true;  
        }
    }
    return false;
} 

