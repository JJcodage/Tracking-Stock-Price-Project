#include <stdio.h>
#define STOCK_MAX 1000000
#define STOCK_MIN 0
#define INPUT_MAX 168000
#define INPUT_MIN 168


int main()
{
    float temp, sum, daily_sum, weekly_sum, max, min, daily_max, daily_min;
    float last_max, last_min, max_avg, min_avg, weekly_max, weekly_min, lw_max, lw_min, lw_avg, ld_sum;
    int n,d;
    
    daily_sum=0;
    weekly_sum=0;
    sum=0;
    n=1;
    d=1;
    
    //scanf("%f",&temp);
    
    /*if(temp<STOCK_MIN || temp>STOCK_MAX)
    return 0;*/
    
    sum=0;
    daily_sum=0;
    max=STOCK_MIN-1;
    min=STOCK_MAX+1;
    daily_max=STOCK_MIN-1;
    daily_min=STOCK_MAX+1;
    weekly_max=STOCK_MIN-1;
    weekly_min=STOCK_MAX+1;
    scanf("%f",&temp);
    sum+=temp;
    daily_sum+=temp;
    
  
    if(temp<daily_min)
        daily_min=temp;
        
    if(temp>daily_max)
        daily_max=temp;
        
    if(temp<min)
        min=temp;
        
    if(temp>max)
        max=temp;
    
   
    while(!feof(stdin)&& n<=INPUT_MAX)
    {
        scanf("%f",&temp);
        
        if(temp<=STOCK_MIN || temp>=STOCK_MAX)
        {
                return 0;                  
        }
        
        sum+=temp;
        daily_sum+=temp;
        
        if(temp<daily_min)
        daily_min=temp;
        
        if(temp>daily_max)
        daily_max=temp;
        
        if(temp<min)
        min=temp;
        
        if(temp>max)
        max=temp;
        
        
        
        n++;
        
        
        
        
        
        
                    
         
        
        
        
        if(n%24==0)                    //daily check 
        {
         
         
         
         
         if(daily_sum/24>max_avg)
         max_avg=daily_sum/24;
         
         if(daily_sum/24<min_avg)
         min_avg=daily_sum/24;
         
         if(daily_max>weekly_max)
         weekly_max=daily_max;
         
         if(daily_min<weekly_min)
         weekly_min=daily_min;
                      
         weekly_sum+=daily_sum;
         ld_sum=daily_sum;
         daily_sum=0;  
         
         last_max=daily_max;
         last_min=daily_min;
         daily_max=STOCK_MIN-1;
         daily_min=STOCK_MAX+1;
         
         
        }
        
        if(n==24)
         {
                   max_avg=sum/24;
                   min_avg=sum/24;
         }
         
        
        if(n%168==0)
         {
           lw_avg=weekly_sum/168;
           lw_max=weekly_max;
           lw_min=weekly_min;
           
           weekly_sum=0;
           weekly_max=STOCK_MIN-1;
           weekly_min=STOCK_MAX+1;
         }
        
        
        
        
        
        
    }
    
    if(n<INPUT_MIN)
    {
                   printf("There is not enought input to calculate");
                   return 0;
    }
    //output here
    printf("\nThe maximum stock price observed over all days %.2f", max);
    printf("\nThe minimum stock price observed over all days %.2f", min);
    printf("\nThe overall average of stock prices %.2f", sum/n);
    printf("\nMaximum of the last week's observed stock prices %.2f", lw_max);
    printf("\nMinimum of the last week's observed stock prices %.2f", lw_min);
    printf("\nAverage of the last week's observerd stock prices %.2f", lw_avg);
    printf("\nMaximum of the last day's observed stock prices %.2f", last_max);
    printf("\nMinimum of the last day's observed stock prices %.2f", last_min);
    printf("\nAverage of the last days's observerd stock prices %.2f", ld_sum/24);
    printf("\nMaximum of the daily average stock prices of the last 7 days %.2f", max_avg);
    printf("\nMinimum of the daily average stock prices of the last 7 days %.2f", min_avg);
    //printf("\n%d", n);
    
    
}
