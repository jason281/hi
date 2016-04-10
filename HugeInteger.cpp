#include <iostream>
#include <string>
#include "HugeInteger.h"
using namespace std;


HugeInteger::HugeInteger (){
	data=NULL;
	length=0;
	sign=false;
}
HugeInteger::HugeInteger (int value){
	length=1;
	int num=value;
	while(num>=10){
     num=num/10;
	 length+=1;
	}
	num=value;
	data=new int [length];
	for(int i=0;i<length;i++){
	  data[i]=num%10;
	  num/=10;
	}
}

HugeInteger::HugeInteger (string value)
{
       length=value.size();
		   
	data=new int [length];
	for(int i=1;length>=i;i++){
	  data[length-i]=value[i-1]-48;
	  
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
HugeInteger& HugeInteger::operator=(const HugeInteger& pt){
	delete [] data;
	length=pt.length;
	sign=pt.sign;
	data= new int[length];
	for(int i=0;i<length;i++)
       data[i]=pt.data[i];
   return *this;
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
	c.data=new int [c.length];
	for(int i=0;i<c.length;i++)
		c.data[i]=0;
	for(int i=0;i<c.length;i++){
		if((smalllength-i)>0) {
		    if( (data[i]+pt.data[i])<10){
	        	c.data[i]+=data[i]+pt.data[i];
	      	}
	      	else{
	      		c.data[i]+=data[i]+pt.data[i]-10;
	      		c.data[i+1]+=1;
	       }
	    }
		else{
		   	if(pt.length>length){
		        if( (c.data[i]+pt.data[i])<10){
	           		c.data[i]=c.data[i]+pt.data[i];
	         	}
	        	else{
	           		c.data[i]=c.data[i]+pt.data[i]-10;
	           		c.data[i+1]+=1;
	         	}
		   	}
		   	else{		   
		        if( (c.data[i]+data[i])<10){
	           		c.data[i]=c.data[i]+data[i];
	         	}
	         	else{
	           		c.data[i]=c.data[i]+data[i]-10;
	           		c.data[i+1]+=1;
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
	c.data=new int[c.length];
	for(int i=0;i<c.length;i++)
		c.data[i]=0;
	for(int i=0;i<c.length;i++){
		if((smalllength-i)>0) {
	 	    if( (data[i]-pt.data[i])>=0){
		    	c.data[i]+=data[length-i]-pt.data[i];
		    }
		    else{
		    	c.data[i]=data[i]-pt.data[i]+10;
		    	c.data[i+1]-=1;
		    }
	    }
		else{
		   	if(pt.length>length){
		        if( (c.data[i]+pt.data[i])>=0){
	           		c.data[i]=c.data[i]+pt.data[i];
	         	}
	        	else{
	           		c.data[i]=c.data[i]+pt.data[i]+10;
	           		c.data[i+1]-=1;
	         	}
		   	}
		   	else{		   
		        if( (c.data[i]+data[i])>=0){
	           		c.data[i]=c.data[i]+data[i];
	         	}
	         	else{
	           		c.data[i]=c.data[i]+data[i]+10;
	           		c.data[i+1]-=1;
	         	}
			}
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
