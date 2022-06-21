    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>

    #define SIZE 1024

        int main(int argc, char const *argv[])
        {
          
            char *c = (char *) malloc(SIZE*sizeof(char));
            int fdr,fdw;
            
             fdr = open(argv[1],O_RDONLY);

               if (fdr == -1)
               {
                   perror("Error occured in opening file and the error is -");
                   exit(EXIT_FAILURE);
               }

               fdw = open(argv[2], O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);

               if (fdw == -1)
              {
                  perror("Error occured in reading file and the error is -");
                  exit(EXIT_FAILURE);
              }

              while(read(fdr,c,SIZE))
              {
                  write(fdw,c,SIZE);
              }

           
              close (fdr);
              close (fdw);
             exit(EXIT_SUCCESS);
          }
        
