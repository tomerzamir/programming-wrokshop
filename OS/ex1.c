#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main()
{
    int pid, stat;
    char* params[] = { "",NULL };
    char com[1000];
    char* o_path = getenv("PATH");

    char* token;
    char path[1000];
    strcpy(path, o_path);

    char dir[1000];
    
    while (1)
    {
        if ((pid = fork()) == 0) // child
        {
            

    			
    			token = strtok(path, ":");
      			printf("enter your command:\n"); // print prompt
      			scanf("%s", com);              // scan sh command
      			if (!(strcmp(com, "leave")))
      			{
       				printf("bye :]\n");
           			exit(1);
      			}
      			
          	 	while (token != NULL)
         	  	 {
           	  	   strcpy(dir, token);
           	  	   strcat(dir, "/");
           		     //
          		   strcat(dir, com);
            	   execv(dir, params);
            	                    			
                	
          	      token = strtok(NULL, ":");
           		 }
           		printf("exec failed...please try again:\n");
          		break;

        	}
       
        else // parent
        {
            wait(&stat);
		
            if (stat != 0)
            {
            	exit(1);
            }
        }
    }
}




