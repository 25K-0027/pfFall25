#include <stdio.h>

double repay(double loan, double rate, int years, double inst, double extra, int yr)
{
    if(years <= 0 || loan <= 0){
        return 0;
    }

    double interest = loan * rate;

    double principal = inst;
    if(principal > loan)
        principal = loan;

    double extraPay = extra;
    if(principal + extraPay > loan)
        extraPay = loan - principal;

    double payment = principal + extraPay + interest;

    double remaining = loan - principal - extraPay;
    if(remaining < 0)
        remaining = 0;

    printf("Year %d: Payment = %.2f , Remaining loan = %.2f\n",
            yr, payment, remaining);

    return payment + repay(remaining, rate, years-1, inst, extra, yr+1);
}


double calculateRepayment(double loan, double rate, int years, double extra)
{
    if(loan<=0 || years<=0){
        printf("Invalid input\n");
        return 0;
    }

    double inst = loan / years;

    printf("Starting Loan: %.2f\n", loan);
    printf("Interest Rate: %.2f%%\n", rate*100);
    printf("Years: %d\n", years);
    printf("Fixed Installment: %.2f\n", inst);
    printf("Extra Payment: %.2f\n\n", extra);

    double total = repay(loan, rate, years, inst, extra, 1);

    printf("\nTotal amount paid = %.2f\n", total);

    return total;
}


int main()
{
    // Required trace: 100000, 5%, 3 years, no extra
    calculateRepayment(100000, 0.05, 3, 0);

    printf("\n---- Extra Payment Example ----\n");
    calculateRepayment(100000, 0.05, 3, 2000);

    return 0;
}
