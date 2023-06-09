/**
 * @author Abdelrahman Mohamed Elhetamy
 * @file main.c
 * @project Bank System
 * @date 07 June 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "BankSystem.h"


int main()
{
	Client_t * A1 = NULL;
	
	A1 = CreateClientList();	//Creating the very first list of our clients data
	
	int ID,Funct,validation=0,options = 0,EditOptions=0,UpdatedID=0,UpdatedPass=0;
	char name[20];
	int ExitCondition;
	int Pass;
	
	
	printf("Welcome to HSBC Bank\n");
	printf("Please Enter your functionality \n1-Admin\t2-Client\n");
	scanf("%d",&Funct);		//take Funct Variable to determine which if the user is an admin or client
	printf("Please Enter your ID and password\n");
	scanf("%d",&ID);		//Scan the user ID
	scanf("%d",&Pass);		//Scan the user Password
	if(Funct == 2)	//Check for the Funct variable if it's an admin or client in this case it will be a client
	{
		validation=ValidateClient(A1,ID,Pass);	//Check for the ID and Password Entered by the user
		if(validation ==1 )
		{
			printf("Valid Client\n");		
			PrintClientDetails(A1,ID,Pass);		//Call the function to print the client data which is the only available option for the client
			
		}
		else
		{
			printf("Invalid Client");
		}
	}
	else if(Funct == 1)		//Admin Case
	{
		validation = ValidateAdmin(ID,Pass);	//Check for the ID and Password Entered by the user
		if(validation ==1 )
		{
			printf("Valid Admin\n");		
			while(ExitCondition != 1)	//Here it's an exit criteria which will be detremined by the admin after any operation done 
			{
				
				printf("Choose one of the following options :\n");
				printf("1-Show Client Deatils\t2-Edit Client Details\t3-Add New Client\t4-Delete Client\n");
				scanf("%d",&options);	//Scan which option the admin want to do
				switch(options)			//Switch case on options for faster exectution
				{
					case 1:
						printf("Please Enter Client Name :	");
						scanf("%s",name);					//First Option (Show Client Details)
						PrintClientDetailsAdmin(A1,name);
						break;
					case 2:
						//Second Option (Edit Client Data)
						printf("Please Enter Client Name :	");
						scanf("%s",name);
						printf("Please Choose what you want to edit:\n1-ID\t2-Password");
						scanf("%d",&EditOptions);
						switch(EditOptions)		//Switch Case to check whether the admin want to chande the ID or Password of the client
						{
							case 1:
								printf("Please Enter The new ID\n");
								scanf("%d",&UpdatedID);
								EditClientDetailsAdmin(A1,name,ID,0);
								break;
							case 2:
								printf("Please Enter The new Password\n");
								scanf("%d",&UpdatedPass);
								EditClientDetailsAdmin(A1,name,0,Pass);
								break;
						}
						break;
					case 3:
							//Third Option (Add New Client)
							AddClient(A1);
							break;
					case 4:
							//Fourth Option (Delete an existing client)
							printf("Please Enter the client name and ID\n");
							scanf("%s%d",name,&ID);
							DeleteClient(A1,name,ID);
							break;
					default:
							printf("Invalid Option\n");
							break;
					}
				printf("\nPress '1' for exit or '-1' to Make another option\n");	//Check whether the admin want to make another option or not
				scanf("%d",&ExitCondition);
			}
		}
		else
		{
			printf("Invalid Admin");
		}
	}
	
}