#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie{
    char name[30];
    char director[30];
    char relDate[30];
    int rating;
    int costPerRent;
    int noOfViews; // in months
    char custId[30];
    char expire[30];
    struct movie *next; //pointer to the next block of memory to find dog structure
};

struct movie *GenerateLinkedList2();
void FillStructData2(struct movie *current); 
void browseEntries(struct movie *current);
struct movie *addNewItem(struct movie *start);
struct movie *addFirstItem();
struct movie *deleteEntry(struct movie *start);
struct movie *modify(struct movie *start);
struct movie *deleteEndNode(struct movie *start);
struct movie *search(struct movie *start);
void monthEarns(struct movie *start);
struct movie *deleteFirstNode(struct movie *start);
void WriteListToFile(struct movie *start);
void CleanUp(struct movie *start);
struct movie *ReadListIn(struct movie *start);
struct movie *ReadNextFromFile(struct movie *start, FILE *pFile);
struct movie *sort(struct movie *start);

int main(){
    int begin;
    int ch;
    int press;
    //you will need a pointer to start of the list. IT SHALL NEVER MOVE*
    //*Unless you re-oder the elements.
    //However ENTRY (FIRST) NODE MUST ALWAYS BE PRESERVED

    struct movie *start;
    start = 0;
    //we will define a second pointer so we can move through the list and find the
    //last entry in the list (for adding new nodes)

    struct movie *move;

    puts(" Press 1 to Start OR 2 to load Previous Data");
    scanf("%d", &begin);
    while ((ch = getchar()) != '\n' && ch != EOF);
    if (begin == 1){
        while (begin == 1){
        
            if (begin == 1){
                puts("PRESS 1 to Add new entries| PRESS 2 to Browse entries | PRESS 3 to Modify entry \n PRESS 4 to Delete Entry | PRESS 5 to Save Entry | PRESS 6 to Sort Entry | PRESS 7 Search Movie Title | PRESS 8 for Monthly Earnings");
                scanf("%d", &press);
                while ((ch = getchar()) != '\n' && ch != EOF) ;
                    
                if (press == 1)
                {
    
                    if (start == 0) { 
                        start = addFirstItem(); 
                    } else { 
                        addNewItem(start); 
                    }

                }else if (press == 2)
                {
                    browseEntries(start);
                }else if (press == 3)
                {                        
                    modify(start);
                }else if (press == 4)
                {
                    start=deleteEntry(start);
                }else if (press == 5)
                {
                    WriteListToFile(start);
                }else if (press == 6)
                {
                    start = sort(start);
                }else if (press == 7)
                {
                    search(start);
                }else if (press == 8)
                {
                    monthEarns(start);
                }else{
                    puts("INVALID INPUT! READ THE INSTRUCTIONS");
                    exit(1);
                }
            }
        }
    }else if (begin == 2){
        puts("Loading Previously Stored Data");
        start = ReadListIn(start);

        while (begin == 2){
        
            if (begin == 2){
                puts("PRESS 1 to Add new entries| PRESS 2 to Browse entries | PRESS 3 to Modify entry \n PRESS 4 to Delete Entry | PRESS 5 to Save Entry | PRESS 6 to Sort Entry | PRESS 7 Search Movie Title | PRESS 8 for Monthly Earnings");
                scanf("%d", &press);
                while ((ch = getchar()) != '\n' && ch != EOF) ;
                    
                if (press == 1)
                {
    
                    if (start == 0) { 
                        start = addFirstItem(); 
                    } else { 
                        addNewItem(start); 
                    }

                }else if (press == 2)
                {
                    browseEntries(start);
                }else if (press == 3)
                {                        
                    modify(start);
                }else if (press == 4)
                {
                    start=deleteEntry(start);
                }else if (press == 5)
                {
                    WriteListToFile(start);
                }else if (press == 6)
                {
                     start = sort(start);
                }else if (press == 7)
                {
                    search(start);
                }else if (press == 8)
                {
                    monthEarns(start);
                }else{
                    puts("INVALID INPUT! READ THE INSTRUCTIONS");
                    exit(1);
                }
            }
        }
    }else{
        
        puts("INVALID INPUT! READ THE INSTRUCTIONS");
        exit(2);
    } 
       
    return 0;
}

struct movie *GenerateLinkedList2(){
    //need a series of pointers
        //start <= reference to the first node i out list. it shall not change
        //current <= a pointer that we will move throughout ou list.
        //          It shall be reference to the current block being accessed.
        //last <= a pointer to the last node/block referenced
    struct movie *start, *current, *last;

    int count = 0;
    char keep = 'y';
    int ch;

    while (keep == 'y'){
        
        if (count == 0){

            //set up first node. asign start
            current = (struct movie*)malloc(sizeof(struct movie));
            if (current == NULL) {
                puts("MEMORY ALLOCATION ERROR. Node 1. Exiting...");
                exit(1);
            }

            start = current;
            count++;
            FillStructData2(current);
            current->next = 0;
            last = current;
        }else
        {
            //set up next node. link to last node
            current = (struct movie*)malloc(sizeof(struct movie));
            if (current == NULL) {
                puts("MEMORY ALLOCATION ERROR. Node 1. Exiting...");
                exit(1);
            }
            count++;
            FillStructData2(current);
            current->next = 0;
            last->next = current; // link it to a memory before last = current;
            last = current;
        }

        puts("Enter new Movie? y/n\n");
        scanf("%c", &keep);
        while ((ch = getchar()) != '\n' && ch != EOF);
    }

    return start;
}
//fill data
void FillStructData2(struct movie *current){
    int ch;
    puts("Enter Movie Name: ");
    scanf("%s", current->name);
    while ((ch = getchar()) != '\n' && ch != EOF);

    puts("Enter Director's Name: ");
    scanf("%s", current->director);
    while ((ch = getchar()) != '\n' && ch != EOF);

    puts("Enter Release Date: ");
    scanf("%s", current->relDate);
    while ((ch = getchar()) != '\n' && ch != EOF);

    puts("Enter Rate from 1-10: ");
    scanf("%d", &current->rating);
    while ((ch = getchar()) != '\n' && ch != EOF);

    puts("Enter Cost Per Rental: ");
    scanf("%d", &current->costPerRent);
    while ((ch = getchar()) != '\n' && ch != EOF);

    puts("Enter Number of Views in Months: ");
    scanf("%d", &current->noOfViews);
    while ((ch = getchar()) != '\n' && ch != EOF);

    puts("Enter CUSTOMER ID: ");
    scanf("%s", current->custId);
    while ((ch = getchar()) != '\n' && ch != EOF);

    puts("Enter Rental Expiration: ");
    scanf("%s", current->expire);
    while ((ch = getchar()) != '\n' && ch != EOF);
}
//Browse Entries
void browseEntries(struct movie *current){
    struct movie *move;
    int count = 0;
    int check;

    //move through the list and display
    move = current;
    while (move->next != 0){
        count++;
        printf("\nEntry NO: %d\n", count);
        printf("Movie Name: %s \n",move->name);
        printf("Director: %s \n",move->director);
        printf("Released Date: %s \n",move->relDate);
        printf("Rating: %d \n",move->rating);
        printf("Cost Per Rent: %d \n",move->costPerRent);
        printf("No of Views: %d \n",move->noOfViews);
        printf("Customer ID: %s \n",move->custId);
        printf("Expire: %s \n",move->expire);
        puts("---------------------------------------");

        if (move->next != 0)
        {
            int ch;
            puts("Press 1 to keep browsing entries ||Press 2 to stop");
            scanf("%d", &check);
            while ((ch = getchar()) != '\n' && ch != EOF);
            if (check == 1)
            {
                move = move->next;
            }else if (check == 2)
            {
                break;
            }
          
        }
        
    }

    if (check != 2) {
        count++;
        printf("Entry: %d\n", count);
        printf("Movie Name: %s \n",move->name);
        printf("Director: %s \n",move->director);
        printf("Released Date: %s \n",move->relDate);
        printf("Rating: %d \n",move->rating);
        printf("Cost Per Rent: %d \n",move->costPerRent);
        printf("No of Views: %d \n",move->noOfViews);
        printf("Customer ID: %s \n",move->custId);
        printf("Expire: %s \n",move->expire);
        puts("End of list\n");
    }

}

//Adding First Node
struct movie *addFirstItem(){ 
    struct movie *start, *current, *last;
    int ch;
    //set up first node. asign start
    current = (struct movie*)malloc(sizeof(struct movie));
    if (current == NULL) {
        puts("MEMORY ALLOCATION ERROR. Node 1. Exiting...");
        exit(1);
    }

    start = current;
    FillStructData2(current);
    current->next = 0;
    last = current;

    return start;
}
//Adding additional Nodes
struct movie *addNewItem(struct movie *start){
    struct movie  *current, *last;
    current = start;
    int ch;

    while (current->next != 0){
        current = current->next; // link it to a memory before last = current;
    } 
    last = current;
    //set up next node. link to last node
    current = (struct movie*)malloc(sizeof(struct movie));
    if (current == NULL) {
        puts("MEMORY ALLOCATION ERROR. Node 1. Exiting...");
        exit(1);
    }

    FillStructData2(current);
    current->next = 0;
    last->next = current;

    return current;
}
//Modifying
struct movie *modify(struct movie *start){
    struct movie  *current, *last;
    current = start;
    int ch, count, entry;
    puts("Enter the number of entry you want to modify\n");
    scanf("%d", &entry);
    while ((ch = getchar()) != '\n' && ch != EOF);
    count = 0;
    while (current->next != 0){
       
        
        count++;
        if (entry == count)
        {
            break;
        }
         current = current->next;
    
    }
  
    FillStructData2(current);            
}
//Delete Entry
struct movie *deleteEntry(struct movie *start){
    struct movie  *current, *last ,*previous;
    current = start;
    int ch, count, entry;
    puts("Enter the number of entry you want to DELETE\n");
    scanf("%d", &entry);
    while ((ch = getchar()) != '\n' && ch != EOF);
    
    count = 0;
    //deleting First Entry
    if (entry == 1){
                    
        start = deleteFirstNode(start);        

    }else{

        while (current->next != 0){
   
            count++;
            
            if (entry == count)
            {
            
                break;
            }
            previous = current;
            current = current->next;
    
        }
        if (current->next != 0){
            previous->next = current->next;
            free(current);
            puts("\nThe selected Entry has been deleted\n");
            current = previous->next;
        }else
        {            
            deleteEndNode(start);                        
        }   
    }   
    return start;          
}

//Deleting first node
struct movie *deleteFirstNode(struct movie *start){
    struct movie  *current, *last, *move ,*previous;
    current = start;

    if (start != NULL && start != 0) 
    {
        current = start->next;
    }
    free(start);
    start = current;
    return current;

}

//Deleting Last Node
struct movie *deleteEndNode(struct movie *start){
    struct movie  *current, *last ,*previous;
    current = start;

    if(current == 0){
        puts("Deletion not possible");
    }else{
        previous = 0;
        last = current;
        while(last->next != 0){
            previous = last;
            last = last->next;
        }
        if (previous == 0){
            current = 0;
        }else
        {
            previous->next = 0;
            free(last);
        }
        
    }
}
//Search Function with movie name as search key
struct movie *search(struct movie *start){
    struct movie  *current, *last, *move ,*previous;
    current = start;
    int ch;
    char entry[30];
    puts("Enter the movie name to search for\n");
    scanf("%s", &entry);
    while ((ch = getchar()) != '\n' && ch != EOF);
    while (current != 0)
    {
        if(strcmp(current->name, entry) == 0){
            move=current;
            puts("\nMATCH FOUND\n");
            printf("Movie Name: %s \n",move->name);
            printf("Director: %s \n",move->director);
            printf("Released Date: %s \n",move->relDate);
            printf("Rating: %d \n",move->rating);
            printf("Cost Per Rent: %d \n",move->costPerRent);
            printf("No of Views: %d \n",move->noOfViews);
            printf("Customer ID: %s \n",move->custId);
            printf("Expire: %s \n",move->expire);
            break;
        }
        current = current->next;
    }
    
}
//Calculating Movie Monthly Earns
void monthEarns(struct movie *start){
    struct movie  *current, *last, *move ,*previous;
    current = start;
    double total = 0.00;

    while (current->next != 0){
   
        total += (current->costPerRent * current->noOfViews);
    
        current = current->next;
    
    }

    total += (current->costPerRent * current->noOfViews);

    printf("\nRental Monthly Earnings: %.2f\n", total);

}

// Write Data or save data to file
void WriteListToFile(struct movie *start) {
	FILE *pFile;
	pFile = fopen("project.bin", "wb");
    
	
	if(pFile != 0) {
        struct movie  *current, *holdNext, *move ,*holdPrevious;
        current = start;		
		holdNext = 0;
		holdPrevious = 0;
		
		while(current != 0) {
			holdNext = current->next;
						
			current->next = NULL;
						
			fseek(pFile, 0, SEEK_END);
			fwrite(current, sizeof(struct movie), 1, pFile);
			
			printf("Writing:%s to file\n",current->name);
			
			current->next = holdNext;
			
			
			holdNext = NULL;
			holdPrevious = NULL;
			
			current = current->next;
		}
		fclose(pFile);
		pFile = NULL;
	} else {
		printf("FILE OPEN ERROR\n");
	}
	
}

//Cleanup function
void CleanUp(struct movie *start) {
    struct movie  *current, *freeMe, *holdMe;	
	freeMe = start;
	holdMe = NULL;	
	while(freeMe != NULL) {
		holdMe = freeMe->next;
		printf("Free Name:%s is now free\n",
			freeMe->name);
		free(freeMe);
		freeMe = holdMe;
	}	
}

//Read  next From File
struct movie *ReadNextFromFile(struct movie *start, FILE *pFile) {
	size_t returnValue;
	if(start == NULL) {
		start = malloc(sizeof(struct movie));
		returnValue = fread(start, sizeof(struct movie), 1, pFile);
		start->next = NULL;
	} else {
		struct movie *indexMovie = start;
		struct movie *newMovie = malloc(sizeof(struct movie));
		while(indexMovie->next != NULL) {
			indexMovie = indexMovie->next;
		}
		returnValue = fread(newMovie, sizeof(struct movie), 1, pFile);
		indexMovie->next = newMovie;
		newMovie->next = NULL;
		
	}
	return start;
}
// Main Reading from file
struct movie *ReadListIn(struct movie *start) {
	
	FILE *pFile;
	pFile = fopen("project.bin", "rb");
	if(pFile != NULL) {
	
		CleanUp(start);
		start = NULL;
		
		fseek(pFile, 0, SEEK_END);
		long fileSize = ftell(pFile);
		rewind(pFile);
		
		int numEntries = (int)(fileSize / (sizeof(struct movie)));
		printf("numEntries:%d\n",numEntries);
		
		int loop = 0;
		for(loop = 0; loop < numEntries; ++loop) {
			fseek(pFile, (sizeof(struct movie) * loop), SEEK_SET);
			start = ReadNextFromFile(start, pFile);
		}
	}  else {
		printf("FILE OPEN ERROR FOR READ\n");
	}
	
	return start;

}
//Sorting Function
struct movie *sort(struct movie *m_array){
    struct movie *m1, *m2;
    struct movie *temp;

    int noOfNodes = 1;

    while(m_array != 0) {
        noOfNodes++;
    }
    //noOfNodes++;
    m1 = m_array;
    for (int i = 0; i < noOfNodes-1; i++)
    {
        m2=m1;
        for (int j = i+1; j < noOfNodes; j++)
        {
            m2 = m2->next;
            if (strcmp(m1->name, m2->name) > 0)
            {
            //    temp->next = m1->next;
            //    m1->next = m2->next;
            //    m2->next = temp->next;

                strcpy(temp->name, m1->name);
                strcpy(temp->director, m1->director);
                strcpy(temp->relDate, m1->relDate);               
                temp->rating = m1->rating;
                temp->costPerRent = m1->costPerRent;
                temp->noOfViews = m1->noOfViews; 
                strcpy(temp->custId, m1->custId);
                strcpy(temp->expire, m1->expire);
                //temp->next = i->next;

                strcpy(m1->name, m2->name);
                strcpy(m1->director, m2->director);
                strcpy(m1->relDate, m2->relDate);               
                m1->rating = m2->rating;
                m1->costPerRent = m2->costPerRent;
                m1->noOfViews = m2->noOfViews; 
                strcpy(m1->custId, m2->custId);
                strcpy(m1->expire, m2->expire);
                //i->next = j->next;

                strcpy(m2->name, temp->name);
                strcpy(m2->director, temp->director);
                strcpy(m2->relDate, temp->relDate);               
                m2->rating = temp->rating;
                m2->costPerRent = temp->costPerRent;
                m2->noOfViews = temp->noOfViews; 
                strcpy(m2->custId, temp->custId);
                strcpy(m2->expire, temp->expire);
                //j->next = i->next;
            
            }
            
        }
        m1 = m1->next;
    }
    m_array = m1;
    return m_array;
}        
       
    

