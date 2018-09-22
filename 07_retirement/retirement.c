#include<stdlib.h>
#include<stdio.h>

typedef struct _retire_info {
  int months;
  double contribution; // dollars contributed or spent in month
  double rate_of_return;
} retire_info; 

void print_monthly_info(int months, double balance) {
  printf("Age %3d month %2d you have $%.2lf\n", months / 12, months % 12, balance);

  return;
}

double balance_calc(double balance, retire_info retire_stats) {
  balance += balance * retire_stats.rate_of_return;
  balance += retire_stats.contribution;

  return balance;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
  // Set balance at initial to start
  double balance = initial;
  int total_months = startAge;

  for (int i = 0; i < working.months; i++) {
    total_months += 1;
    print_monthly_info(total_months, balance); 
    balance = balance_calc(balance, working);
  }

  for (int j = 0; j < retired.months; j++) {
    total_months += 1;
    print_monthly_info(total_months, balance);
    balance = balance_calc(balance, retired);
  }

  return;
}

int main() {
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045 / 12.0;
  
  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 / 12.0;

  retirement(327, 21345, working, retired);

  return 0;
}
