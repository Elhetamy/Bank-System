/**
 * @author Abdelrahman Mohamed Elhetamy
 * @file BankingSystem.c
 * @project Bank System
 * @date 07 June 2023
 */



#include <stdio.h>
#include <stdlib.h>
#include "BankSystem.h"
#include "string.h"


const Admin_t admin[ADMIN_SIZE] = {{900,900},
	{901,500}};
	/************************************	CLIENT FUNCTIONS	*******************************/
/**
 * @brief This Function is responsible for initialize the database of the bank system by creating an objects of struct client which we defined in the header file
 * @return Pointer to starting object of struct client
 */
Client_t* CreateClientList(void)
{
	Client_t * Start = NULL;

	Client_t * Current=(Client_t*)malloc(sizeof(Client_t));

	Current->details.client_ID = 100;

	Current->details.client_password=100;

	strcpy(Current->details.client_name,"Abdelrahman");
	
	Current->details.client_budget=5000;
	Current->Link=NULL;
	Start = Current;
	
	Current=(Client_t*)malloc(sizeof(Client_t));

	Current->details.client_ID = 101;

	Current->details.client_password=120;

	strcpy(Current->details.client_name,"Ahmed");

	Current->details.client_budget=4000;
	Current->Link=NULL;
	Start->Link = Current;
	
	
	return Start;
}

/**
 * @brief This function is responsible for printing the Client Details
 * @param Start pointer to the first element of our linked list
 * @param ClientID	Check for the client id to see if it matches with any client of the bank database or not
 * @param ClientPassword ClientID	Check for the client id to see if it matches with any client of the bank database or not
 */
void PrintClientDetails(Client_t* Start,char ClientID,char ClientPassword)
{
	Client_t* ptr = Start;
	while((ptr!= NULL))
	{

		if((ptr->details.client_ID == ClientID) && (ptr->details.client_password == ClientPassword))
		{
			printf("Welcome Mr %s : \n" , ptr->details.client_name);
			printf("Your Current Budget is %d",ptr->details.client_budget);
			break;
		}
		ptr= ptr->Link;
	}
	
}

/**
 * @brief This function is responsible for checking if the entered id and password for the client are valid or not	
 * @param Start pointer to the first element of our linked list
 * @param ClientID	Check for the client id to see if it matches with any client of the bank database or not
 * @param ClientPassword Check for the client password to see if it matches with any client of the bank database or not
 * @return it returns 1 if the ID and Password are valid and -1 otherwise 
 */
char ValidateClient(Client_t* Start,char ClientID,char ClientPassword)
{
	Client_t* ptr = Start;
	char valid = -1;
	while((ptr!= NULL))
	{

		if((ptr->details.client_ID == ClientID) && (ptr->details.client_password == ClientPassword))
		{
			valid = 1;
			break;
		}
		ptr= ptr->Link;
	}
	return valid;
}
	
	
	/************************************	ADMIN FUNCTIONS	*******************************/
/**
 * @brief This function is responsible for checking if the entered id and password for the admin are valid or not
 * @param AdminID Check for the Admin id to see if it matches with any Admin of the bank database or not
 * @param AdminPassword Check for the Admin password to see if it matches with any client of the bank database or not
 * @return it returns 1 if the ID and Password are valid and -1 otherwise
 */
char ValidateAdmin(short unsigned int AdminID,short unsigned int AdminPassword)
{
	char valid = -1;
	int iterator = 0;
	while(iterator < ADMIN_SIZE)
	{
		if(admin[iterator].Admin_ID == AdminID && admin[iterator].Admin_Password == AdminPassword)
		{
			valid = 1;
			break;
		}
		iterator++;
	}
	return valid;
}

/**
 * @brief This Function is used in the first option of the admin options to print the client details you want
 * @param Start pointer to the first element of our linked list
 * @param cn The name we want the system to search about if it's there or not in the database
 */
void PrintClientDetailsAdmin(Client_t* Start,char cn[])
{
	Client_t* ptr = Start;
	while((ptr!= NULL))
	{

		if(!strcmp(ptr->details.client_name , cn))
		{
			printf("\nThe Client Details is: \n");
			printf("Mr %s : \n" , ptr->details.client_name);
			printf("Client ID is %d \n",ptr->details.client_ID);
			printf("Client Password is %d \n",ptr->details.client_password);
			printf("Client Current Budget is %d",ptr->details.client_budget);
			break;
		}
		ptr= ptr->Link;
	}
	if(ptr == NULL)
	{
		printf("Client Not Found!");
	}
}

/**
 * @brief This Function is used in the second option of the admin options to Edit the client details you want
 * @param Start	pointer to the first element of our linked list
 * @param cn The name we want the system to search about if it's there or not in the database
 * @param NewID The new ID you want to assign to the client 
 * @param NewPassword The new ID you want to assign to the client 
 * @return pointer to the first element of editied the list
 */
Client_t* EditClientDetailsAdmin(Client_t* Start,char cn[],char NewID,char NewPassword)
{
	Client_t* ptr = Start;
	while((ptr!= NULL))
	{

		if(!strcmp(ptr->details.client_name , cn))
		{
			if(NewID!=0 && NewPassword==0)
			{
				ptr->details.client_ID = NewID;
				printf("Changes Done!\n");
				break;
			}
			else if(NewID==0 && NewPassword!=0)
			{
				ptr->details.client_password = NewPassword;
				printf("Changes Done!\n");
				break;
			}
			
		}
		ptr= ptr->Link;
	}
	return Start;
}

/**
 * @brief This Function is used in the Third option of the admin options to Add a new client to the system
 * @param Start pointer to the first element of our linked list
 * @return pointer to the first element of editied the list
 */
Client_t* AddClient(Client_t *Start)
{
	char name[20];
	int ID,Password,Budget;
	Client_t* ptr = Start;
	Client_t* Temp = (Client_t*) malloc(sizeof(Client_t));
	
	printf("Please Enter New Client Name\n");
	scanf("%s",name);
	printf("Please Enter New Client ID\n");
	scanf("%d",&ID);
	printf("Please Enter New Client Password\n");
	scanf("%d",&Password);
	printf("Please Enter New Client Budget\n");
	scanf("%d",&Budget);
	strcpy(Temp->details.client_name,name);
	Temp->details.client_ID = ID;
	Temp->details.client_password = Password;
	Temp->details.client_budget = Budget;
	while(ptr->Link!=NULL)
	{
		ptr= ptr->Link;
	}
	Temp->Link = ptr->Link;
	ptr->Link = Temp;

	printf("Client Added Successfully!\n");
	return Start;
}

/**
 * @brief This Function is used in the Fourth option of the admin options to Delete an existing client from the system
 * @param Start	pointer to the first element of our linked list
 * @param cn The name we want the system to search about if it's there or not in the database
 * @param ClientID Check for the client id to see if it matches with any client of the bank database or not
 * @return pointer to the first element of editied the list
 */
Client_t* DeleteClient(Client_t* Start,char cn[],char ClientID)
{
	Client_t* Temp = NULL;
	Client_t* ptr= NULL;
	if(Start==NULL)
	{
		printf("List is empty");
	}
	/*Deletion of first node or deletion of only node*/
	else if(!strcmp(Start->details.client_name , cn) && Start->details.client_ID == ClientID)
	{
		Temp= Start;
		Start= Start->Link;
		free(Temp);
		printf("\nNode deleted\n");
	}
	
	/*Deletion of last node or deletion in between nodes*/
	else
	{
		ptr = Start;
		while(ptr->Link != NULL)
		{
			if((!strcmp(ptr->Link->details.client_name , cn)) && ptr->Link->details.client_ID == ClientID)
			{
				break;
			}
			else
			{
				ptr= ptr->Link;
			}
		}
		if(ptr->Link==NULL)
		{
			printf("Client not found\n");
		}
		else
		{
			Temp = ptr->Link;
			ptr->Link= Temp->Link;
			free(Temp);
			printf("\nClient deleted\n");
		}
	}
	return Start;
}