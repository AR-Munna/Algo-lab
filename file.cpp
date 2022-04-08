#include<bits/stdc++.h>
using namespace std;

void file_writer(){
    int n;
    char s[100];
    FILE *fp;

    fp = fopen("C:\\Users\\azad\\Desktop\\CPP\\input.txt", "w");
    if(fp==NULL){
        printf("ERROR\n");
        exit(1);
    } 
    while(1){
        scanf("%d", &n);
        gets(s);
        if(n==-1) break; 
        else fprintf(fp, "%d %s\n", n, s);
    }
    fclose(fp);
}

void file_reader(){
    int n;
    char s[100];
    FILE *fp;

    fp = fopen("C:\\Users\\azad\\Desktop\\CPP\\input.txt", "r");
    if(fp==NULL){
        printf("ERROR\n");
        exit(1);
    } 
    while(fscanf(fp, "%d %s", &n, &s)!=EOF){
        printf("n: %d %s\n", n, s);
    }
    fclose(fp);
}

struct student{
    int id;
    char name[25];
    float gpa;
};

void struct_write_in_file(){
    FILE *fp;
    fp = fopen("C:\\Users\\azad\\Desktop\\CPP\\student_info.txt", "w");
    if(fp==NULL){
        printf("ERROR\n");
        exit(1);
    }
    student array_of_student[5];
    for(int i=0; i<2; i++){
        scanf("%d\n", &array_of_student[i].id);
        //scanf("%s\n", &array_of_student[i].name);
        gets(array_of_student[i].name);
        scanf("%f\n", &array_of_student[i].gpa);
        fprintf(fp, "%d %s %f\n", array_of_student[i].id, array_of_student[i].name, array_of_student[i].gpa);
    }

    //fwrite(array_of_student, sizeof(array_of_student),1,fp);
    fclose(fp);
}

void struct_read_from_file(){
    student array_of_student[5];
    int id;
    char name[25];
    float gpa;
    FILE *fp;
    fp = fopen("C:\\Users\\azad\\Desktop\\CPP\\student_info.txt", "r");
    if(fp==NULL){
        printf("ERROR\n");
        exit(1);
    }

   /* fread(array_of_student, sizeof(array_of_student),1,fp);

    for(int i=0; i<2; i++){
        printf("%d ", array_of_student[i].id);
        puts(array_of_student[i].name);
        printf(" %0.2f\n", array_of_student[i].gpa);
    }*/

    while((fscanf(fp, "%d %f", &id, &gpa)!=EOF)){
        fgets(name, 25, fp);
        printf("%d ", id);
        puts(name);
        printf("%0.2f\n", gpa);
    }
    
    fclose(fp);
}


main(){
    //struct_write_in_file();
    printf("Data in file: \n");
    struct_read_from_file();
    return 0;
}