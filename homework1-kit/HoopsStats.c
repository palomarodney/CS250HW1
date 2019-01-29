#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
//MAKE SURE INITIALIZE POINTERS TO NULL AND CHANGE AFTER 
//declare struct for players
//linked lists 
struct player {
	char lastName[100];
	int jerseyNumber; 
	float appg; 
	int grad; 
	struct player* next; 


};

void sort(struct player* head){
	int sorted = 0; 
	struct player* ptr1; 
	

	if (head == NULL){
		return; 
	}

	while(! sorted){ //loop until everything was swapped
		sorted = 1; 
		ptr1 = head; 
		// loop until there is a next node 
		while (ptr1->next!=NULL){
			if (ptr1->appg < ptr1->next->appg){
				sorted = 0; 
				//swap lastName positions  
				char temp1[100]; 
				strncpy(temp1,ptr1->lastName, 100); 
				strncpy(ptr1->lastName, ptr1->next->lastName,100); 
				strncpy(ptr1->next->lastName,temp1, 100);

				//swap jerseyNumber 
				int temp2= ptr1->jerseyNumber; 
				ptr1->jerseyNumber = ptr1->next->jerseyNumber; 
				ptr1->next->jerseyNumber = temp2; 

				//swap appg 
				float temp3 = ptr1->appg; 
				ptr1->appg = ptr1->next->appg; 
				ptr1->next->appg = temp3; 

				//swap graduation year
				int temp4 = ptr1->grad; 
				ptr1->grad = ptr1->next->grad; 
				ptr1->next->grad = temp4; 

			}
			//if there is a tie between appg 
			if (ptr1->appg == ptr1->next->appg){
				if (strncmp(ptr1->lastName,ptr1->next->lastName,100)>0){
					sorted = 0; 
					//swap lastName positions  
					char t1[100]; 
					strncpy(t1,ptr1->lastName, 100); 
					strncpy(ptr1->lastName, ptr1->next->lastName,100); 
					strncpy(ptr1->next->lastName,t1, 100);

					//swap jerseyNumber 
					int t2= ptr1->jerseyNumber; 
					ptr1->jerseyNumber = ptr1->next->jerseyNumber; 
					ptr1->next->jerseyNumber = t2; 

					//swap appg 
					float t3 = ptr1->appg; 
					ptr1->appg = ptr1->next->appg; 
					ptr1->next->appg = t3; 

					//swap graduation year
					int t4 = ptr1->grad; 
					ptr1->grad = ptr1->next->grad; 
					ptr1->next->grad = t4; 
				}

				
			}
			ptr1= ptr1->next; 
		}
	}


	return; 
}

void print(struct player* head){
	struct player* current = head;
	while (current !=NULL){
		printf("%s ", current->lastName);
		printf("%d ", current->jerseyNumber); 
		printf("%d\n", current->grad); 
		current = current->next; 
	}

	return; 
}

void freePlayer(struct player* head){
	struct player* temp; 
	while (head!= NULL){
		temp = head; 
		head = head->next; 
		free(temp); 
	}
}

int main(int argc, char *argv[1]){
	FILE* stat; 
	// char string[100];
	char str[100];
	stat = fopen(argv[1], "rt" );


	//if name of file doesn't exist
	if (stat == NULL){
		printf("Could not open file");
	}

	char temp_lastName[100];
	int temp_jerseyNumber; 
	float temp_appg; 
	int temp_grad;

	//allocate memory for the head pointer
	// struct players *head_ptr;
	// head_ptr = (struct players*)malloc(sizeof(struct players));

 	//populate head ptr with fscanf
 	// fscanf(stat,"%s", &temp_lastName); 
 	// if (temp_lastName == "DONE"){
 	// 	break;
 	// }
 	  
 	// fscanf(stat,"%d", &temp_jerseyNumber);
 	// fscanf(stat,"%f", &temp_appg);
 	// fscanf(stat,"%d", &temp_grad);


 	// have head ptr point to the next node 
 // 	head_ptr->lastName = temp_lastName;
	// head_ptr->jerseyNumber = temp_jerseyNumber;
	// head_ptr->appg = temp_appg; 
	// head_ptr->grad = temp_grad;

	//move pointer to next node
	// struct players *current;
	// head_ptr->next = current; 
	// current = (struct players*)malloc(sizeof(struct players));

	int counter = 0; 
	struct player* head; 
	struct player* prev; 
	//go line by line in the file
	while (1){
		//test if DONE is written, and if so, exit the while loop
		fscanf(stat,"%s", temp_lastName);
		if (strncmp(temp_lastName,"DONE", 100)==0){
			break;
		}

		//allocate space for player struct 
		struct player* player = (struct player*)malloc(sizeof(struct player));
		player-> next = NULL;
		
		//make the head pointer 
		if (counter ==0){
			head = player; 
			prev = player; 
		}

		//fscanf line by line to populate the the next node
		strncpy(player->lastName, temp_lastName, 100);
		// player->lastName = temp_lastName; 
		
		fscanf(stat,"%d", &temp_jerseyNumber);
		player->jerseyNumber = temp_jerseyNumber;
 		fscanf(stat,"%f", &temp_appg);
 		player->appg = temp_appg;
 		fscanf(stat,"%d", &temp_grad);
 		player->grad = temp_grad; 
 		



		//if the pointer isn't for head 
		if (counter>0){
			prev->next=player; 
			prev=player; 
		}

		counter ++; 
	
	}
	fclose(stat);
	sort(head); 
	print(head); 
	freePlayer(head);
		//traverse through linked list 
			// on each line, print each node's  last name, jersey number, and graduation year

	 
return 0; 
	}
	
	
