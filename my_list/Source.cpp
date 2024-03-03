#include <iostream>
#include "TList.h"
#include "TPolinom.h"
#include "TMonom.h"
int main()
{
    TPolinom res;
    
    int masres[][2] = { {3,934},{8,235 },{-1,123 },{17,120 } };
    int mas[][2] = { {8,235},{-3,231},{-6,123 },{9,120 } };
    int mas1[][2] = { {3,934},{3,231},{5,123 }, {8,120 } };
    TPolinom pol_project1(mas, 4);
    TPolinom pol_project2(mas1, 4);
    TPolinom pol_project(masres, 4);
   // std::cout << pol_project1;
   res = pol_project1 + pol_project2;


    std::string a = res.ToString(); int ind;
  //for (pol_project.Reset(); !pol_project.IsEnd(); pol_project.GoNext())
  //{
  //    ind = pol_project.GetCurrentItem().Get_index();
  //    std::cout << ind;

  //}
  
     bool equal=pol_project == res;
    std::cout << a << std::endl;
     std::cout << equal;
}