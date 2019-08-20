/* Calculate deflection of supported beam under a central load
   from data supplied in an external text file. C++ Compiler */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
  vector<int> foo;
  double nume, denom, len2;

  ifstream infile;
  infile.open("beam.dat", ios::in);

  if(!infile){
    cout << "Error finding input file" << endl;
    system("pause");
    exit(-1);
  }

  int number;
  while(infile >> number){

    foo.push_back(number);

  }
  infile.close();

  cout << "Length of beam (feet): "<< foo[0] <<"\n\n";
  cout << "Central force (lb): "<< foo[1] <<"\n\n";
  cout << "Modulus of Elasticity (lb/in^2): "<< foo[2] <<"\n\n";
  cout << "Moment of Inertia (in^4): "<< foo[3] <<"\n\n";

  len2 = foo[0]*12.0;
  nume = foo[1]*len2*len2*len2;
  denom = 48.0*foo[2]*foo[3];

  cout <<"deflection is: "<< nume/denom <<"\n";
  return (0);
}
