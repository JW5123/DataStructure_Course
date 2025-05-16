#include <stdio.h>
union member{
    struct company{
        char id[10];
        char name[30];
        char fax[12];
        char tel[12];
    }c;
    struct person{
        char id[10];
        char name[10];
        char tel[12];
    }p;
}m;
int main(){
    char inp;
    printf("請問您的組織是->1.公司 2.個人:");
    inp = getchar();
    printf("\n\n");
    printf("請輸入資料\n");
    if(inp == '1'){
        printf("統編:");
        scanf("%s", m.c.id);
        printf("公司:");
        scanf("%s",m.c.name);
        printf("傳真:");
        scanf("%s", m.c.fax);
        printf("電話:");
        scanf("%s", m.c.tel);
        printf("您輸入的資料->統編%s, 公司%s, 傳真%s, 電話%s", m.c.id, m.c.name, m.c.fax, m.c.tel);
    }
    else if(inp == '2'){
        printf("編號:");
        scanf("%s", m.p.id);
        printf("姓名:");
        scanf("%s", m.p.name);
        printf("電話:");
        scanf("%s", m.p.tel);
        printf("您輸入的資料->編號%s, 姓名%s,電話%s", m.p.id, m.p.name, m.p.tel);
    }
    else{
        printf("無此項目...");
    }
    printf("\n");
    return 0;
}