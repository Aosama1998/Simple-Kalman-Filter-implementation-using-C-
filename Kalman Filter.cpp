
#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main ()
{

// Variables initialization according to values provided in the main problem

    float U_node = -2;
    float VK = 0.05;
    float Y_1 = 2.2;

 // declaring  our variables as matrices using the eigen library functions and methods 

    Matrix<float , 2 , 1 >X_Pos_Predicteded;  // The X position predicted state is declared as a matrix 
    Matrix<float , 2 , 1 >X_Pos_Correcteded;  //The true value of x position as a corrected state after calculations are performed is declared as a matrix 

    Matrix<float,2,2>PK_Corrected;
    Matrix<float,2,2>QK;
    Matrix<float,2,1>XK_Predicted;
    Matrix<float,2,2>FK;
    Matrix<float,2,1>XK;
    Matrix<float,2,1>GK;
    Matrix<float,1,2>HK;
    Matrix<float,2,2>P_predicted;
    Matrix<float,2,1>K;

  
    
// Inititaliznig the matrices using the values given in the problem

    HK<<1,0;
    FK<<1,0.5,0,1;
    XK<<0,5;
    GK<<0,0.5;
    PK_Corrected<<0.01,0,0,1;
    QK<<0.1,0,0,0.1;



    X_Pos_Predicted=(FK*XK)+(GK*(U_node));  // Claculation of X position in the predicted state using kalman equations
 
    P_predicted=FK*PK_Corrected*FK.transpose()+QK;   // Claculation of P variable in the predicted state using kalman equations
  

    /----------correction--------------/
    K=P_predicted*HK.transpose()*pow((HK*P_predicted*HK.transpose()+VK),-1);  // Claculation of Actual X position in the corrected state using kalman equations

    X_Pos_Corrected=X_Pos_Predicted+K*(Y_1-(HK*X_Pos_Predicted));      // Claculation of Actual P variable in the predicted state using kalman equations
    

}