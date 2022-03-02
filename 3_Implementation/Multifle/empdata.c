#include <stdio.h> 
#include <stdlib.h>
#include <string.h>  
void flush()
{
    int a;
    while ((a = getchar()) != '\n' && a != EOF);
}
struct emp{
        char ename[40]; 
        int eage; 
        float sal; 
    }t;
  int main(){
    FILE *fp, *ft; 
    char another, choice;
    char empname[40]; 
    long int recsize; 
    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL){
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL){
            printf("Connot open file");
            exit(1);
        }
    }
    recsize = sizeof(t);
    while(1){
        printf("1. Add Record\n"); 
        printf("2. List Records\n"); 
        printf("3. Modify Records\n"); 
        printf("4. Delete Records\n"); 
        printf("5. Exit\n"); 
        printf("Your Choice: "); 
        fflush(stdin); 
        scanf("\n%c", &choice);
        switch(choice){
            case '1':  
                fseek(fp,0,SEEK_END); 
                another = 'y';
                while(another == 'y'){ 
                    flush();
                    printf("\nEnter name: ");
                    fgets(t.ename, 40, stdin);
                    printf("\nEnter age: ");
                    scanf("%d", &t.eage);
                    printf("\nEnter basic salary: ");
                    scanf("%f", &t.sal);
                    fwrite(&t,recsize,1,fp); 
                    printf("\nAdd another record(y/n) ");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
                break;
            case '2':
                rewind(fp); 
                while(fread(&t,recsize,1,fp)==1){ 
                    printf("\n%s %d %.2f\n",t.ename,t.eage,t.sal); 
                }
                break;
            case '3':  
                another = 'y';
                while(another == 'y'){
                    printf("Enter the employee name to modify: ");
                    scanf("%s", empname);
                    rewind(fp);
                    while(fread(&t,recsize,1,fp)==1){ 
                        if(strcmp(t.ename,empname) == 0){ 
                            printf("\nEnter new name,age and bs: ");
                            scanf("%s%d%f",t.ename,&t.eage,&t.sal);
                            fseek(fp,-recsize,SEEK_CUR); 
                            fwrite(&t,recsize,1,fp); 
                            break;
                        }
                    }
                    printf("\nModify another record(y/n)");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
                break;
            case '4':
                another = 'y';
                while(another == 'y'){
                    flush();
                    printf("\nEnter name of employee to delete: ");
                    fgets(empname,40, stdin);
                    ft = fopen("Temp.dat","wb");  
                    rewind(fp); 
                    while(fread(&t,recsize,1,fp) == 1){ 
                        if(strcmp(t.ename,empname) != 0){ 
                            fwrite(&t,recsize,1,ft); 
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("EMP.DAT"); 
                    rename("Temp.dat","EMP.DAT"); 
                    fp = fopen("EMP.DAT", "rb+");
                    printf("Delete another record(y/n)");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
                break;
            case '5':
                fclose(fp);  
                exit(0); 
        }
    }
    return 0;
}
