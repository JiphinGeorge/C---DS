#include<stdio.h>
int main ()
{
 int arr[20],i,j,temp,n,ele,flag=0,low,high,mid;
 printf("Enter the Number of Elements :\n");
 scanf("%d",&n);
 printf("Enter the  Elemetns :\n");
 
 for(i=0;i<n;i++)
   {
   scanf("%d",&arr[i]);
   }
   
   printf("Unsorted array :\n");
   
	   for(i=0;i<n;i++)
	   {
	   printf("%d ",arr[i]);
	   }
	   printf("\n");
	   //sorting to search 
	   
	   for(i=0;i<n;i++)
	   {
	    for(j=0;j<n-1;j++)
	     {
	        if(arr[j]>arr[j+1])
	        {
	        temp = arr[j];
	        arr[j]=arr[j+1];
	      	arr[j+1]=temp;
	        }
	    
	     }
	   }
	   
	   printf("sorted array :\n");
   
	   for(i=0;i<n;i++)
	   {
	   printf("%d ",arr[i]);
	   
	   }
	   
	   printf("\n enter the Element to Search : \n");
	   scanf("%d",&ele);
	   
	   low=0;
	   high=n-1;
	   while(low<=high)
	   {
	   	mid= low+(high-low)/2;
	   	if(arr[mid]==ele)
	   	{
	   	printf("The Element %d is present at  location %d",ele ,mid+1);
	   	flag =1;
	   	break;
	   	}
	   	else if(ele<arr[mid])
	   	{
	   	 high=mid-1;
	   	 } 
	   	 else
	   	 low = mid+1;
	   	
	   }
	   
	 if(flag==0)
	   	{
	   	 printf("Item %d not found",ele);
	   	 
	   	 }
   return 0;
}

// #include<stdio.h>   // Standard input-output header file

// int main ()
// {
//     int arr[20], i, j, temp, n, ele, flag=0, low, high, mid;

//     // arr[20] -> Array to store max 20 integers
//     // i, j    -> Loop counters
//     // temp    -> Used for swapping in bubble sort
//     // n       -> Number of elements
//     // ele     -> Element to search
//     // flag    -> To indicate whether element is found (1 = found, 0 = not found)
//     // low, high, mid -> Used for binary search

//     printf("Enter the Number of Elements :\n");
//     scanf("%d", &n);   // Input the number of elements

//     printf("Enter the Elements :\n");
//     for(i=0; i<n; i++)  // Input n elements
//     {
//         scanf("%d", &arr[i]);
//     }
   
//     printf("Unsorted array :\n");
//     for(i=0; i<n; i++)   // Display elements before sorting
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     // ---------- Sorting the array (Bubble Sort) ----------
//     for(i=0; i<n; i++)             // Outer loop for passes
//     {
//         for(j=0; j<n-1; j++)       // Inner loop for comparisons
//         {
//             if(arr[j] > arr[j+1])  // If left element is bigger than right
//             {
//                 temp = arr[j];          // Swap
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
   
//     printf("Sorted array :\n");
//     for(i=0; i<n; i++)   // Display sorted array
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     // ---------- Binary Search ----------
//     printf("Enter the Element to Search : \n");
//     scanf("%d", &ele);

//     low = 0;          // Start of array
//     high = n - 1;     // End of array

//     while(low <= high)   // Continue until search space is valid
//     {
//         mid = low + (high - low) / 2;  // Find middle index safely

//         if(arr[mid] == ele)   // If element found
//         {
//             printf("The Element %d is present at location %d", ele, mid+1);
//             flag = 1;   // Mark as found
//             break;
//         }
//         else if(ele < arr[mid])   // If element is smaller, ignore right half
//         {
//             high = mid - 1;
//         }
//         else   // If element is greater, ignore left half
//         {
//             low = mid + 1;
//         }
//     }
   
//     // If element is not found
//     if(flag == 0)
//     {
//         printf("Item %d not found", ele);
//     }

//     return 0;
// }
