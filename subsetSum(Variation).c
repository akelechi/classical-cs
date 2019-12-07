
// Subset Sum problem for 15 integers
//Problem statement: Read a set of 15 integers. Create a subset from them of length k, where you read the value of k from the user. Print the subset with highest sum and the lowest sum, along with the sums.
//Oct 27, 2017



#include<stdio.h>
#include<stdlib.h>

void PrintFirst();
void PrintArray(int[]);
void ScanArray();
void FindSubset(int,int);
void EnterCardinality();
void Initialize(int[]);
void Copy(int[],int[]);

int count,i, arr[15],loop[15], highestSum = 0, lowestSum = 0,iterator = 0;
int currentArray[15],maxArray[15],minArray[15];
main()
{
 printf("\nPlease enter the 15 integers:\n");
 ScanArray();
 printf("\nThe array you entered is\n");
 PrintFirst();
 EnterCardinality();
 Initialize(loop);
 FindSubset(0,0);
 printf("The subset with the highest sum is: ");
 PrintArray(maxArray);
 printf("The subset with the lowest sum is: ");
 PrintArray(minArray);

}

void PrintFirst()
{

for(i = 0; i<15;i++)
{
printf(" %d", arr[i]);
}

}
void EnterCardinality()
{
 
 printf("Please enter the length of the subsets[from 0 to 14]: ");
 scanf("%d", &count);

}

void Initialize(int a[])
{
  for(i=0;i<15;i++)
  {
   a[i] = 0;
  }
}

void PrintArray()
{
  for(i=0;i<15;i++)
  {
    printf(" %d ", arr[i]);
  }
}

void ScanArray()
{
  for(i=0;i<15;i++)
  {
    scanf("%d", &arr[i]);
  }
}

void FindSubset(int start, int currLength)
{
   int currentArray[15], maxArray[15],minArray[15];

if (currLength == count)
{
++ iterator;
  for ( i = 0; i < 15; i++)
     {
	if (loop[i] == 1)
	 {
		currentSum+= arr[i];
        
	 }
        currentArray[i] = arr[i];
     }
        if(iterator==1)
       {
         lowestSum = currentSum;
         Copy(currentArray, minArray);
        }
       if(currentSum > highestSum)
         {
           highestSum = currentSum;
          Copy(currentArray, maxArray);

         }
      else
        if(currentSum< lowestSum)
        {
          lowestSum = currentSum;
          Copy(currentArray, minArray);
          
        }
      
    Initialize(currentArray);
    currentSum = 0;
    return;
}
	if (start == 15)
	{
	return;
        }
	
     loop[start] = 1;
     FindSubset(start + 1, currLength + 1);
     loop[start] = 0;
     FindSubset(start + 1, currLength);
  

}
 
void Copy(int a[], int b[])
{

for(i=0; i<15; i++)
{
b[i] = a[i];
}
}





