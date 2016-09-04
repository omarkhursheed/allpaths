#include<stdio.h>
#include<stdlib.h>
// Defining a structure node that has pointers to four sides of each node
struct node 
	int nodeId;
	struct node * left;
	struct node * right;
	struct node * up;
	struct node * down;
};

int j = 0;
int result[1000];
struct node * add[16];
int main(int argc, char const *argv[])
// Allocating memory to and assigning nodeId to 16 nodes as instructed
{


	void counter(int);
	for (int i =0; i<16; i++){
	add[i] = (struct node *)malloc(sizeof (struct node));
	add[i] -> nodeId = i;
	}	
	int  entry;
	int k;
	
// Pointing from each node to other nodes based on given structure

	add[0] -> right = add[1];
	add[0] -> left = NULL;
	add[0] -> up = NULL;
	add[0] -> down = NULL;

	add[1] -> right = NULL;
	add[1] -> left = NULL;
	add[1] -> up = NULL;
	add[1] -> down = add[5];

	add[2] -> right = NULL;
	add[2] -> left = NULL;
	add[2] -> up = NULL;
	add[2] -> down = NULL;

	add[3] -> right = NULL;
	add[3] -> left = NULL;
	add[3] -> up = NULL;
	add[3] -> down = NULL;

	add[4] -> right = NULL;
	add[4] -> left = NULL;
	add[4] -> up = NULL;
	add[4] -> down = add[8];

	add[5] -> right = add[6];
	add[5] -> left = add[4];
	add[5] -> up = NULL;
	add[5] -> down = add[9];

	add[6] -> right = add[7];
	add[6] -> left = NULL;
	add[6] -> up = NULL;
	add[6] -> down = add[10];

	add[7] -> right = NULL;
	add[7] -> left = NULL;
	add[7] -> up = NULL;
	add[7] -> down = NULL;

	add[8] -> right = add[9];
	add[8] -> left = NULL;
	add[8] -> up = NULL;
	add[8] -> down = add[12];

	add[9] -> right = NULL;
	add[9] -> left = NULL;
	add[9] -> up = NULL;
	add[9] -> down = add[13];

	add[10] -> right = NULL;
	add[10] -> left = NULL;
	add[10] -> up = NULL;
	add[10] -> down = NULL;

	add[11] -> right = NULL;
	add[11] -> left = NULL;
	add[11] -> up = NULL;
	add[11] -> down = NULL;

	add[12] -> right = add[13];
	add[12] -> left = NULL;
	add[12] -> up = NULL;
	add[12] -> down = NULL;

	add[13] -> right = add[14];
	add[13] -> left = NULL;
	add[13] -> up = NULL;
	add[13] -> down = NULL;

	add[14] -> right = add[15];
	add[14] -> left = NULL;
	add[14] -> up = NULL;
	add[14] -> down = NULL;

	add[15] -> right = NULL;
	add[15] -> left = NULL;
	add[15] -> up = NULL;
	add[15] -> down = NULL;

//  Asking user for noedId to print path

	printf("Enter Node Id to print path\n");
	scanf("%d", &entry);
	counter(entry); // function call to get paths from the node "entry"
	
	if (add[entry] -> left == NULL && add[entry] -> right == NULL && add[entry] -> up == NULL && add[entry] -> down == NULL){
		printf("No nodes can be reached from the entered nodeId\n");
	}
	else{
		printf("Nodes with the folowing Node Ids can be reached from the entered Node Id\n");
	for (j = 0; result[j] != 16; j++){

			printf("%d\t", result[j]);
		}
		printf("\n");
	}
}
	
	
void counter(int userent){
	// using recursive calls to traverse all possible paths from a given node until a node is reached that has no pointers away from it
	do {
		if(add[userent] -> left != NULL ){
			result[j] = add[userent - 1] -> nodeId;
			j++; 
			counter(userent - 1);
			}
		if(add[userent] -> right != NULL){
				result[j] = add[userent + 1] -> nodeId;
				j++;
				counter(userent + 1);

			}
			if(add[userent] -> up != NULL){
				result[j] = add[userent - 4] -> nodeId;
				j++;
				counter(userent - 4);
			}
			if(add[userent] -> down != NULL){
				result[j] = add[userent + 4] -> nodeId;
				j++;
				counter(userent + 4);

			}
			if(add[userent] -> left == NULL && add[userent] -> right == NULL && add[userent] -> up == NULL && add[userent] -> down == NULL){
				result[j] = 16;
			}
		}
		while(result[j] != 16);
		
	} 
