#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib> 
#include <iomanip>


using namespace std;

struct Wine{
	string wineName;
	int vintage;
	int rating;
	double price;
};

 
Wine parse_line(string line)         									//To read size of the whole file over and over. It won't stop untill it meets ";"
{
	
    Wine wine;                         
                      
    size_t pos;                                               
    pos = line.find(";");                    
    wine.wineName = line.substr(0,pos);     
    line.erase(0,pos+1);                     
    pos = line.find(";");                     
    wine.vintage = atoi(line.substr(0,pos).c_str());     
    line.erase(0,pos+1);
    pos = line.find(";");
    wine.rating = atoi(line.substr(0,pos).c_str());        
    line.erase(0,pos+1);
    pos = line.find(";");
    wine.price = atof(line.substr(0,pos).c_str());     
    line.erase(0,pos+1);
    return wine;
}
 
void printWine(Wine wine)                                               //to print out content in the file
{
	
    cout << wine.wineName << setw(10) << wine.vintage << setw(5) << wine.rating << setw(5) << wine.price << endl;
    return;
}
 
int main()
{
    const int MAX_SIZE = 100;    
    Wine wineList[MAX_SIZE];    
 
    ifstream infile;                                			 		// to open winelist and cout error message if not exist
    infile.open("winelist.txt"); 
    if(!infile.is_open())
        cout << "File not exist" << endl;
    int i = 0;
    string line;         
    while (getline(infile,line))                      				
    {
        
        wineList[i] = parse_line(line);               					//to enter the input to array
        
        i++;
    }
    char again = 'Y';     
    int input1,input2;     
    
    while (again == 'y' || again == 'Y')     
    {
		
		cout<< "choose the function you want, A for rate, B for price ";
		char control;
		cin >> control;
		
        cout << "Type the  first input: ";
        cin >> input1; 
        cout << "Type the second  input:";
        cin >> input2;
        cout << "Wine name: "<< "               " << "Vintage: " << "          " << "Rating: " << "          " << "Price: " << endl;        // prints the title of the printout.
        cout <<"-----------" << "               " << "---------" << "          " << "--------" << "          " << "--------" << endl;        
        double avgprice=0;
         int count=0;
         double sum=0;
        for(int i = 0; i < 100; i++)
          {
			  if (control == 'A')
            { 
			
              if(wineList[i].rating >= input1 && wineList[i].rating<= input2)            
               {        
                    printWine(wineList[i]);                
                    sum+=wineList[i].price;
                    count++;
                    avgprice=sum/count;
               }  
            
           }
                                                                        //To check the range of the price for winlist
                                                                        //To get the average price
            
            else if (control =='B')
            {
              if(wineList[i].price >= input1 &&wineList[i].price<= input2)
              { 
				 printWine(wineList[i]);
		          sum+=wineList[i].price;
                  count++;
                  avgprice=sum/count;
                 
		      }   
		    }
        
            
            
          }
           cout<<"\n"<<"average price is"<<" "<<avgprice<<endl;         
           cout << "go again? (y/n) "<< endl;                                       
                    cin >> again;
        
 
   } 
}  
