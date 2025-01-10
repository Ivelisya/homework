// #include <cstdio>
#if 0
1. 设计一个客户信息管理系统，要求输入5个客户的信息（姓名、年龄、购买金额）。系统需要执行以下操作，请补完该程序让其可以运行。
（1）按客户的购买金额从高到低排序并输出客户的姓名、年龄和购买金额(8分)
（2）输出购买金额最高的客户的姓名和购买金额（4分）
（3）反转购买金额最高客户的姓名并输出（3分）

#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char customers[5][3][50] = {{"zhangsan", "20", "100"},
                              {"lisi", "21", "200"},
                              {"wangwu", "22", "300"},
                              {"zhaoliu", "23", "400"},
                              {"sunqi", "24", "500"}};

  // 按购买金额从高到低
  // 使用冒泡排序
  for (int i = 0; i < 5 - 1; i++) {
    for (int j = 0; j < 5 - i - 1; j++) {
      if (atof(customers[j][2]) < atof(customers[j + 1][2])) {
        char temp[50];
        strcpy(temp, customers[j][0]);
        strcpy(customers[j][0], customers[j + 1][0]);
        strcpy(customers[j + 1][0], temp);

        strcpy(temp, customers[j][1]);
        strcpy(customers[j][1], customers[j + 1][1]);
        strcpy(customers[j + 1][1], temp);

        strcpy(temp, customers[j][2]);
        strcpy(customers[j][2], customers[j + 1][2]);
        strcpy(customers[j + 1][2], temp);
      }
    }
  }
  for (int i = 0; i < 5; i++) {
    printf("%s姓名 %s年龄 %s金额\n", customers[i][0], customers[i][1],
           customers[i][2]);
  }
  int len = strlen(customers[0][0]);
  for (int i = 0; i < len / 2; ++i) {
    char temp = customers[0][0][i];
    customers[0][0][i] = customers[0][0][len - i - 1];
    customers[0][0][len - i - 1] = temp;
  }
}