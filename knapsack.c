//Knapsack Problem for 15 items
//Oct 27, 2017

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void ScanArray(float[]);
void PrintArray(float[]);
void SortAll();
void CreateUnitValue();
void Optimize();
void ClearArray(float[]);
void Copy(float[], float[]);
void DisplayResults(float[]);
void Swap(int, int, float[]);

int count0, n = 15;
float weight[15], value[15], valuePerWeight[15], maxWeight;
main()
{
printf("\nPlease enter the different weights\n");
ScanArray(weight);
PrintArray(weight);
printf(" ");

printf("\nPlease enter the respective values of the weights previously entered\n");
ScanArray(value);
PrintArray(value);
printf(" ");

printf("\nPlease enter the maximum weight the bag can hold ");
scanf("%f",&maxWeight);

CreateUnitValue();
SortAll();
Optimize();

}

void DisplayResults(float res[])
{
   printf("You should select the following weights");
   
  for(count0 = 0 ; count0 < n; i++)
    {
        if(res[count0]!= 0)
      printf(" %f , ", res[count0]);
    }
   
}

void ClearArray(float a[])
{
   for( count0 = 0; count0 < n; count0++)
      {
        a[count0] = 0;
      }

}
void Copy(float a[], float b[])
{
    for(count0 = 0; count0 < n; count0++)
      {
        b[count0] = a[count0];
      }

}

void SortAll()
{
  int temp,inner, outer;
  for( outer  = n; outer>=1; outer--)
    {
      for(inner = 0; inner<outer; inner++)
        if(valuePerWeight[inner] < valuePerWeight[inner+1])
        {
          Swap(inner, inner+1, valuePerWeight);
          Swap(inner, inner+1, weight);
          Swap(inner, inner+1, value);
        }
    }



}

void Swap(int a , int b, float Arr[])
{
  temp = Arr[a];
  Arr[a] = Arr[b];
  Arr[b] = temp;

}
void CreateUnitValue()
{
  for(int count0 = 0; count0 < n ;  i++)
   {
  valuePerWeight[count0] = (value[count0])/(weight[count0]);

   }

}
void ScanArray(float Arr[])
{
  for(count0 = 0; count0 < n; count0++)
    {
      scanf(" %f ", &Arr[count0]);
    }
}
void PrintArray(float Arr[])
{
printf("\nThe values you entered is\n");
   for(count0 = 0; count0 < n; count0++)
    {
      printf(" %f ", Arr[count0]);
    }
}

void Optimize()
{
float currentValue,previousValue = 0;
 
float tempWeight[n], knapSack[n], currentWeight= 0, cValue=0, pValue=0;
int i,j;

for ( i = 0; i < n; i++)
  {
  if(weight[i]<= maxWeight)
   {
  tempWeight[i] = weight[i];
  currentWeight+= weight[i];
  cValue+= value[i];

for(j = i+1 ; j < n ; j++)
{
if(weight[j] + currentWeight <= maxWeight)
{
  currentWeight+= weight[j];
  tempWeight[j] = weight[j];
  cValue+= value[j];
}

if(cValue >= pValue)
 {
Copy(tempWeight, knapSack);
 pValue = cValue;
ClearArray(tempWeight);
 currentWeight = 0;

  }

}
    }
   
  }
  DisplayResults(knapSack); 
}



 