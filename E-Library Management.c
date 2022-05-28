//E-Library Management project

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void welcome_screen();
void password();
void main_menu();
void addbook();
void viewbook();
void searchbook();
void editbook();
void deletebook();
void about();
void exits();

struct Book_info
{
     int id;
     char name[10];
     char author[10];
     int quantity;
     int rack;

};
   struct Book_info a;
   FILE *file, *file2;

   int p = 1;
   int main()
{
   password();
}
   void main_menu()
{
   system("cls");
   int n;
   printf("\n\n \t\t\t\t\t\t*******************************");
   printf("\n\n \t\t\t\t\t\t********** MAIN MENU **********");
   printf("\n\n \t\t\t\t\t\t*******************************\n");

   printf("\n\t\t 1.ADD BOOK\n");

   printf("\n\t\t 2.VIEW BOOK\n");

   printf("\n\t\t 3.SEARCH BOOK\n");

   printf("\n\t\t 4.EDIT BOOK\n");

   printf("\n\t\t 5.DELETE BOOK\n");

   printf("\n\t\t 6.ABOUT\n");

   printf("\n\t\t 7.EXIT\n");



    printf("\n \t\t Enter your choice: ");
    scanf("%d",&n);

    if(n==1)
    {
        addbook();
    }
    else if(n==2)
    {
        viewbook();
    }
    else if(n==3)
    {
       searchbook();
    }
    else if(n==4)
    {
        editbook();
    }
    else if(n==5)
    {
        deletebook();
    }
    else if(n==6)
    {
      about();
    }
    else if(n==7)
    {
      exits();
    }
    else
    {
        printf("\n\t\tYOUR CHOICE IS WRONG!\n\t\t PLEASE TRY AGAIN...");
        fflush(stdin);
        getchar();
        main_menu();
    }

}
void addbook()
{
    system("cls");
    int d,count=0;

    printf("\n\n\t\t############ADD BOOK############\n\n");
    file = fopen("book.dat","ab+");
    printf("\t\t Enter ID: ");
    fflush(stdin);
    scanf("%d",&d);

    rewind(file);
    while(fread(&a,sizeof(a), 1, file)==1)
   {
       if(d==a.id)
       {
         printf("\n\n\t\tTHIS BOOK IS ALREADY IN LIBRARY...");
         count=1;
       }
   }
   if(count==1)
   {
      fflush(stdin);
      getchar();
      main_menu();
   }
   a.id =d;
   printf("\n\t\t Enter Book Name: ");
   fflush(stdin);
   gets(a.name);
   printf("\t\tEnter Author Name: ");
   fflush(stdin);
   gets(a.author);
   printf("\t\tEnter Quantity: ");
   fflush(stdin);
   scanf("%d",&a.quantity);
   printf("\t\tEnter Rack Number: ");
   fflush(stdin);
   scanf("%d",&a.rack);

   fseek(file, 0, SEEK_END);
   fwrite(&a,sizeof(a), 1,file);
   fclose(file);

   printf("\n\n\t\t ADD BOOK IS SUCCESSFULLY DONE!......");
   fflush(stdin);
   getchar();
   main_menu();
}
void viewbook()
{
    system("cls");
    int count=0;
    printf("\n\n\t\t############VIEW BOOKS############\n\n");
    printf("\tID\tNAME\t\tAUTHOR\t\tQUANTITY\tRACK\n\n");
    file = fopen("book.dat","rb");
    while(fread(&a, sizeof(a),1,file)==1)
    {
        printf("\t%d",a.id );
        printf("\t%s\t",a.name );
        printf("\t%s\t",a.author );
        printf("\t%d\t",a.quantity );
        printf("\t%d\n",a.rack );

        count = count+a.quantity;

    }
     fclose(file);
     printf("\n\n\t\t*****\n");
     printf("\n\t\tTOTAL NUMBER OF BOOKS: %d",count);
     printf("\n\n\t\tPRESS ANY KEY....");
     fflush(stdin);
     getchar();
     main_menu();
}
  void searchbook()
  {
      int d,count=0;
      system("cls");
      printf("\n\n\t\t############SEARCH BOOKS############\n\n");
      printf("\n\t\tSearching.......\n\n");

      file = fopen("book.dat","rb");
      printf("\n\t\tEnter ID: ");
      scanf("%d",&d);
       while(fread(&a, sizeof(a),1,file)==1)
       {
           if(d==a.id)
           {
               printf("\n\n\t\tBOOK IS FOUND\n");
               printf("\t\t ID: %d",a.id);
               printf("\n\t\t NAME: %s",a.name);
               printf("\n\t\t AUTHOR NAME: %s",a.author);
               printf("\n\t\t QUANTITY: %d",a.quantity);
               printf("\n\t\t RACK: %d",a.rack);
               count =1;
           }
       }

       if(count==0)
       {
            printf("\n\n\t\tBOOK IS NOT FOUND!\n");
       }
       printf("\n\n\t\tPRESS ANY KEY.....");
       fflush(stdin);
       getchar();
       main_menu();


  }
  void editbook()
  {
      system("cls");
      int d,count=0;
      printf("\n\n\t\t############EDIT BOOKS############\n\n");
      file = fopen("book.dat","rb+");
      printf("\n\t\tEnter ID: ");
      scanf("%d",&d);
       while(fread(&a, sizeof(a),1,file)==1)
       {
           if(d==a.id)
           {
               printf("\n\n\t\tBOOK IS available\n");
               printf("\n\n ID: %d",a.id);

               printf("\n\t\t ENTER NEW NAME :");
               scanf("%s",a.name);

               printf("\n\t\t ENTER NEW AUTHOR NAME : ");
               scanf("%s",a.author);

               printf("\n\t\t ENTER NEW QUANTITY:");
               scanf("%d",&a.quantity);

               printf("\n\t\t ENTER NEW RACK NUMBER:");
               scanf("%d",&a.rack);

               fseek(file,ftell(file)-sizeof(a),0);
               fwrite(&a, sizeof(a),1,file);
               fclose(file);
               count =1;
           }
      }
      if(count==0)
       {
            printf("\n\n\t\tBOOK IS NOT AVAILABLE!\n");
       }
       printf("\n\n\t\tPRESS ANY KEY.....");
       fflush(stdin);
       getchar();
       main_menu();

  }
  void deletebook()
  {
       int d,count=0;
       system("cls");
       printf("\n\n\t\t############DELETE BOOK############\n\n");
       printf("\n\t\tEnter ID of book to delete: ");
       scanf("%d",&d);
       file = fopen("book.dat","rb+");

         while(fread(&a, sizeof(a),1,file)==1)
       {
           if(d==a.id)
           {
               printf("\n\n\t\tBOOK IS available\n");
               printf("\n\t\tBook name is: %s ",a.name);
               printf("\n\t\tRack no is: %d ",a.rack);
               count=1;
           }
  }

   if(count==0)
       {
            printf("\n\n\t\tBOOK IS NOT AVAILALE!\n");
       }
    else
       {
         file2 = fopen("text.dat","wb+");
         rewind(file);
          while(fread(&a, sizeof(a),1,file)==1)
       {
           if(d!=a.id){

                fseek(file2, 0, SEEK_CUR);
                fwrite(&a, sizeof(a),1,file2);

           }
   }
   fclose(file);
   fclose(file2);

   remove("book.dat");
   rename("text.dat","book.dat");
   file = fopen("book.dat","rb");
   fclose(file);

}

       printf("\n\n\t\tPRESS ANY KEY.....");
       fflush(stdin);
       getchar();
       main_menu();
  }

  void about()
  {
      system("cls");
      printf("\n\n\t\t############ABOUT############\n\n");
      printf("\t\t THIS IS A LIBRARY PROJECT\n\n");
      printf("\n\n\tLast Updated: 11.05.2022\n\n\t");
      printf("\n\n\tTeam:2\n\n\tTeam Members:");
      printf("\n\n\tNAHIAN SYED AHANAF\n\tID: 2212705642");
      printf("\n\n\tMEHEDI HASSAN ROKTIM\n\tID: 2212497");
      printf("\n\n\t\tPRESS ANY KEY TO BACK MAIN MENU.....");
      printf("\n\n\t\t THANK YOU\n\n");

    fflush(stdin);
    getchar();
    main_menu();



  }
  void exits()
  {
      system("cls");


    printf("\n\t   _       .-\"--._");
    printf("\n\t  / \\     /   __\\");
    printf("\n\t  ||\\\\   /  /`(");
    printf("\n\t  || \\\\ _| '``'-.");
    printf("\n\t  | \\_\\\\ `      9\\              ,");
    printf("\n\t   \\_      9    _ '-.=      .--'|}");
    printf("\n\t    |  _        \\)   |     /    /}}");
    printf("\n\t     \\/   = \\   ;_.'/    .=\\.--'`\\}");
    printf("\n\t     |       -__.;---.//` '---./'");
    printf("\n\t      '._..-'`        `|   _   _ _   _   _  _   _  _");
    printf("\n\t       /        .-./   | _| | | | / _ \\ | \\| | | |/ /");
    printf("\n\t    .-'       .-'   |||      | |  |   | |   | |  ` | |   <");
    printf("\n\t .-/         /      |\\\\      ||  ||| ||| ||\\_| ||\\\\");
    printf("\n\t{  |        /_     /  \\|           _ _   _   _ _");
    printf("\n\t -\\          `\\--;              | | | /   \\ | | |");
    printf("\n\t    '-.         |  |              \\   / | | | | | |");
    printf("\n\t       )       / /                ||  \\_/ \\_/");
    printf("\n\t      /    __.'  '--.");
    printf("\n\t     (      '--. _)))");
    printf("\n\t      `-..__)))");


    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t   THANK YOU SO MUCH\n");
    getch();
  }

   void welcome_screen()
{
    system("cls");
    system("color 5F");

 printf("\t\n\t\t\t\t\t||//===================\\\|//===================\\||");
 printf("\t\n\t\t\t\t\t                ________________                 ");
 printf("\t\n\t\t\t\t\t****           |                |            ****");
 printf("\t\n\t\t\t\t\t****           |   Welcome to   |            ****");
 printf("\t\n\t\t\t\t\t****           |        |       |            ****");
 printf("\t\n\t\t\t\t\t****           |        |       |            ****");
 printf("\t\n\t\t\t\t\t****           |  NSU E-LIBRARY |            ****");
 printf("\t\n\t\t\t\t\t****           |        |       |            ****");
 printf("\t\n\t\t\t\t\t****           |________________|            ****");
 printf("\t\n\t\t\t\t\t****                    |                    ****");
 printf("\t\n\t\t\t\t\t****                    |                    ****");
 printf("\t\n\t\t\t\t\t||/====================\\|/===================\\||");
 printf("\t\n\t\t\t\t\t`   --------------------_-------------------''\n\n\n");
}
  void password()
{
  welcome_screen();
  char password1[50]= {"library"};
  char password2[50];

  printf("\n \t\t Enter password: ");
  scanf("%s",&password2);

  if(strcmp(password1, password2)==0)
  {
    printf("\n\n \t\tLogin Sucessfull!\n");
    printf("\n \t\tPRESS ANY KEY....");
  }
  else
  {
      if(p == 3)
      {
          exit(0);
      }
      printf("\n\n \t\tWRONG PASSWORD! you have %d to 3 times\n",p);
      printf("\n\n\t\t\t\t\t\t  PLEASE TRY AGAIN!.......");
      p++;

      fflush(stdin);
      getchar();
      password();
  }
  fflush(stdin);
  getchar();
  main_menu();

}
