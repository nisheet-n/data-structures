#include<stdio.h>                                                     //pow(x,y)=exp(ln(a)*b)  This logic is used to execute pow function. This is good for speed but not good for accuracy
#include<math.h>                                                      //Thats why we use round()

int even(int num,int size)
    {
        int temp=0;                                                    //Temp is a temporary value which will store the odd position values
        int index=0;                                                   //Index is the position of the value stored in temp

        if(size%2==0)                                                  //when the number has even no. of digits
        {
            for (int i = 0 ; i < size; i++)
            { 
            if (i%2!=0)                                                //Odd postion values are being evaluated                    
                {   
                        temp = temp+(num%10)*round(pow(10,index));             //LOGIC: The last value of num is being extracted and checked whether it is at odd position
                        index++;                                        //If yes then it is added to temp multiplied to the 10 to the power of index    
                }
            num=num/10;                                                 //The last digit of the original num is being removed as already evaluated
          
            }
        
        }     
        else                                                           //when the number has odd no. of digits
        { 
            for (int i = 0 ; i < size; i++)
            {
            if (i%2==0)                                                //Even postion values are being evaluated                    
                {  
                        temp = temp+(num%10)*round(pow(10,index));             //LOGIC: The last value of num is being extracted and checked whether it is at even position
                        index++;                                        //If yes then it is added to temp multiplied to the 10 to the power of index
  
                }
                
            num=num/10;                                                 //The last digit of the original num is being removed as already evaluated
          
            }
        
        }

        num=temp;

        return num;
    }


int even_debug(int num,int size)
    {
        int temp=0;                                                    //Temp is a temporary value which will store the odd position values
        int index=0;                                                   //Index is the position of the value stored in temp

        if(size%2==0)                                                  //when the number has even no. of digits
        {
            for (int i = 0 ; i < size; i++)
            { 
            if (i%2!=0)                                                //Odd postion values are being evaluated                    
                {   
                    int check;                                         //Check is being used for debugging
                    check=(num%10)*round(pow(10,index));
                    printf("\nTemp1: %d    Index1:  %d\n",temp,index);  //Temp1 and Index1 are the values of temp and index before extraction of value 
                    printf("Number:  %d\n",num);                        //Original number value before extraction
                    printf("Check Value:  %d\n",check);                 //Check is the value that is being added to temp
                    
                        temp = temp+(num%10)*round(pow(10,index));             //LOGIC: The last value of num is being extracted and checked whether it is at odd position
                        index++;                                        //If yes then it is added to temp multiplied to the 10 to the power of index

                    printf("Temp2: %d    Index2:  %d\n",temp,index);    //Temp2 and Index2 are the values of temp and index after extraction of value
                       
                }
            num=num/10;                                                 //The last digit of the original num is being removed as already evaluated
          
            }
        
        }     
        else                                                           //when the number has odd no. of digits
        { 
            for (int i = 0 ; i < size; i++)
            {
            if (i%2==0)                                                //Even postion values are being evaluated                    
                {   
                    int check;                                         //Check is being used for debugging
                    check=(num%10)*round(pow(10,index));
                    printf("\nTemp1: %d    Index1:  %d\n",temp,index);  //Temp1 and Index1 are the values of temp and index before extraction of value 
                    printf("Number:  %d\n",num);                        //Original number value before extraction
                    printf("Check Value:  %d\n",check);                 //Check is the value that is being added to temp
                    
                        temp = temp+(num%10)*round(pow(10,index));             //LOGIC: The last value of num is being extracted and checked whether it is at even position
                        index++;                                        //If yes then it is added to temp multiplied to the 10 to the power of index

                    printf("Temp2: %d    Index2:  %d\n",temp,index);    //Temp2 and Index2 are the values of temp and index after extraction of value
                       
                }
                
            num=num/10;                                                 //The last digit of the original num is being removed as already evaluated
          
            }
        
        }

        num=temp;

        return num;
    }



int main()
{
    int num,size=0;

    printf("Enter a number:  ");
    scanf("%d",&num);

    int temp=num;

    while (temp%10!=0)                  //For getting the size of the number
    {
        size++;
        temp=temp/10;
    }

    temp=num;

    printf("\nThe Size of %d is:  %d\n",num,size);
    num=even(num,size);
    printf("\nThe new number is:  %d",num);

    printf("\n\n****DEBUGGING****\n");

    num=temp;
    printf("\nThe Size of %d is:  %d\n",temp,size);
    num=even_debug(num,size);
    printf("\nThe new number is:  %d",num);

return 0;
}