#include <iostream>
#include<string>
#include "HugeInteger.h"
using namespace std;


HugeInteger::HugeInteger (){}
HugeInteger::HugeInteger (int value){
	
	int length=1;
	
	int num=value;
	while(num>=10){
     num=num/10;
	 length+=1;
	}
	num=value;
	data=new int [length];
	for(int i=1;length>=i;i++){
	  data[length-i]=num%10;
	  num/=10;
	}

}

HugeInteger::HugeInteger (string value)
{
       length=value.size();
		   
	data=new int [length];
	for(int i=1;length>=i;i++){
	  data[length-i]=value[length-i]-48;
	  
    }
}
HugeInteger::HugeInteger( HugeInteger &pt )
{
	length=pt.length;
	sign=pt.sign;
	data= new int[length];
	for(int i=0;i<length;i++)
       data[i]=pt.data[i];
  
}
HugeInteger:: ~HugeInteger(){
  delete [] data;
  data=NULL;
}
HugeInteger HugeInteger:: add( HugeInteger &pt){
	
	  HugeInteger c;
      int smalllength;
	if(	length<pt.length){
	c.length=pt.length;
	smalllength=length;
	}
	else{
	
	c.length=length;
	smalllength=pt.length;
	}
	
	  for(int i=1;i<=c.length;i++){

		 if((smalllength-i)>=0) {

 	      if( (data[length-i]+pt.data[pt.length-i])<10){
	        c.data[c.length-i]=data[length-i]+pt.data[pt.length-i];
	      }
	      else{
	      c.data[c.length-i]=data[length-i]+pt.data[pt.length-i]-10;
	      c.data[c.length-i-1]+=1;
	       }
	     }
		 else{
		   if(pt.length>length){
 	         if( (c.data[c.length-i]+pt.data[pt.length-i])<10){
	           c.data[c.length-i]=c.data[c.length-i]+pt.data[pt.length-i];
	         }
	         else{
	           c.data[c.length-i]=c.data[c.length-i]+pt.data[pt.length-i]-10;
	           c.data[c.length-i-1]+=1;
	         }
		   }
		   else{		   
 	         if( (c.data[c.length-i]+data[length-i])<10){
	           c.data[c.length-i]=c.data[c.length-i]+data[length-i];
	         }
	         else{
	           c.data[c.length-i]=c.data[c.length-i]+data[length-i]-10;
	           c.data[c.length-i-1]+=1;
             }
  		   }
		 }	 
	  }
		  return c;
	}

HugeInteger HugeInteger:: subtract( HugeInteger &pt){

	  HugeInteger c;
      int smalllength;
	if(	length<pt.length){
	c.length=pt.length;
	smalllength=length;
	}
	else{
	
	c.length=length;
	smalllength=pt.length;
	}
	
	  for(int i=1;i<=c.length;i++){

		 if((smalllength-i)>=0) {

 	      if( (data[length-i]-pt.data[pt.length-i])>=0){
	        c.data[c.length-i]=data[length-i]-pt.data[pt.length-i];
	      }
	      else{
	      c.data[c.length-i]=data[length-i]-pt.data[pt.length-i]+10;
	      c.data[c.length-i-1]-=1;
	       }
	     }
		 else{
	           c.data[c.length-i]=c.data[c.length-i]+pt.data[pt.length-i];
		 }
	  }
		  return c;
}
void HugeInteger:: output(){

	for(int i=1;i<=length;i++){
	  cout<<data[length-i];
    }	
}
 bool HugeInteger:: isEqualTo( HugeInteger &b){
	int j=0;
	for(int i=0;i<length;i++){
	  if(data[i]!=b.data[i]){
       j++;

      }  
	}
	if(j>0){
	sign=false;
	}
	else{
	
	sign=true;
	}
 return sign;
}

bool HugeInteger:: isNotEqualTo( HugeInteger &b){
    int 	j=0;
	for(int i=0;i<length;i++){
	  if(data[i]!=b.data[i]){
       j++;

      }  
	}
	if(j>0){
	sign=true;
	}
	else{
	
	sign=false;
	}
 return sign;
}
bool HugeInteger::  isLessThan( HugeInteger &b){


    int j=0;
	for(int i=0;i<length;i++){
	 
	   	while(data[i]>b.data[i]){
      
		  j++;
       break;
      }  
	}
	if(j>0){
	sign=true;
	}
	else{
	
	sign=false;
	}
 return sign;
}
