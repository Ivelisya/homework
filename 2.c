#if 0
2.  设计一个程序来管理公司员工信息，文件名为 employee.txt，要求实现以下功能：
（1）定义结构体存储员工的姓名、职位和薪资，输入员工信息。（4分）
（2）从文件 employee.txt 中读取员工姓名、职位、薪资，并输出这些数据。（4分）
（3）使用指针修改某个员工的薪资。（4分）
（4）按照员工薪资从高到低排序，并将排序后的数据写入文件 reemployee.txt。
#endif
#include <stdio.h>
#include <string.h>
struct Employee {
  char name[50];
  char position[50];
  float salary;
};
int main() {
  FILE *fp = fopen("employee.txt", "w");
  struct Employee employees[5];
  for (int i = 0; i < 5; ++i) {
    fscanf(fp, "%s %s %f", employees[i].name, employees[i].position,
           employees[i].salary);
  }
  fclose(fp);
  for (int i = 0; i < 5; ++i) {
    printf("%s %s %f\n", employees[i].name, employees[i].position,
           employees[i].salary);
  }
  float *salartPtr = &employees[0].salary;
  *salartPtr = 1000;
  for (int i = 0; i < 5 - 1; ++i) {
    for (int j = 0; j < 5 - i - 1; ++j) {
      if (employees[j].salary < employees[j + 1].salary) {
        struct Employee temp = employees[j];
        employees[j] = employees[j + 1];
        employees[j + 1] = temp;
      }
    }
    FILE *fp = fopen("reemployee.txt", "w");
    for (int i = 0; i < 5; ++i) {
      fprintf(fp, "%s %s %f\n", employees[i].name, employees[i].position,
              employees[i].salary);
    }
    fclose(fp);
  }
}