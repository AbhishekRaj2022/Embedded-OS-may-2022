    #include <stdio.h>
    #include <stdlib.h>

    #define SIZE 1024

        int main(int argc, char const *argv[])
        {
          
            char *c = (char *) malloc(SIZE*sizeof(char));
            FILE *fdr,*fdw;
            
             fdr = fopen(argv[1],"r");

               if (fdr == NULL)
               {
                   perror("Error occured in opening file and the error is -");
                   exit(EXIT_FAILURE);
               }

               fdw = fopen(argv[2],"w+");

               if (fdw == NULL)
              {
                  perror("Error occured in reading file and the error is -");
                  exit(EXIT_FAILURE);
              }

              while(fscanf(fdr,"%s\n",c)!= EOF)
              {
                  fprintf(fdw,"%s\n",c);
              }

           
              fclose (fdr);
              fclose (fdw);
             exit(EXIT_SUCCESS);
          }
        
        
        
        
        
       