#include<iostream>
#include<cmath>
using namespace std;

void BisectionMethod();
void SimpleIterationMethod();
void NewtonsMethod();

int main()
{
    int n = 0;
    do
    {   
    her:
        cout << "1- To Bisection method" << endl;
        cout << "2- To SimpleIteration method" << endl;
        cout << "3- To Newtons method" << endl;
        cout << "4- To Exit" << endl;
        cout << "Enter the number you choose : ";
        cin >> n;   
            switch (n)
            {
            case 1:
                cout << "\n--------------------------------------------------------\n";
                BisectionMethod();
                cout << "\n\n";
                break;
            case 2:
                cout << "\n--------------------------------------------------------\n";
                SimpleIterationMethod();
                cout << "\n\n";
                break;
            case 3:
                cout << "\n\n";
                NewtonsMethod();
                cout << "\n\n";
                break;
            case 4:
                break;
            default:
                cout << "\n--------------------------------------------------------\n";
                cout << "Error! --> chose avalid number" << endl;
                cout << "\n\n";
                goto her;
            }        
    } while (n!=4);
    

}

void BisectionMethod()
{
    double x;
    double f_x = pow(x, 6) - x - 1;
    double a, b;
    cout << "Enter the interval point :" << endl;
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin >> b;
    double f_a = pow(a, 6) - a - 1;
    double f_b = pow(b, 6) - b - 1;

    double c;
    for (int i = 0; i < 4; i++)
    {
        c = (a + b) / 2;
        double f_c = pow(c, 6) - c - 1;
        if ((f_c > 0 && f_a > 0) || (f_c < 0 && f_a < 0))
        {
            a = c;
        }

        if ((f_c > 0 && f_b > 0) || (f_c < 0 && f_b < 0))
        {
            b = c;
        }
    }
    cout << "___________________________________________________" << endl;
    cout << "c = " << c << endl;
}

void SimpleIterationMethod()
{
    double x, x0;
    double f_x = pow(x, 3) - (2 * x) - 5;
    cout << "Enter the initial point x0 : ";
    cin >> x0;
    x = (pow(x, 3) - 5) / 2;
    double xPar = (1.5) * pow(x, 2);
    double xPar_x0 = (1.5) * pow(x0, 2);

    if (xPar_x0 < 1)
    {
        for (int i = 0; i < 7; i++)
        {
            x = (pow(x0, 3) - 5) / 2;
            x0 = x;
        }
    }
    else
    {
        x = pow(((2 * x) + 5), (0.333333333));
        xPar = (0.666666667) * pow(((2 * x) + 5), (-0.666666667));
        xPar_x0 = (0.666666667) * pow(((2 * x0) + 5), (-0.666666667));
        if (xPar_x0 < 1)
        {
            for (int i = 0; i < 3; i++)
            {
                x = pow(((2 * x0) + 5), (0.333333333));
                x0 = x;
            }
        }
    }
    cout << "___________________________________________________" << endl;
    cout << "x = " << x;
}

double setData(string str)
{
    cout<<str;
    double value;
    cin>>value;
    return value;
}
void NewtonsMethod()
{
    //!Initial points
    double x1, x2;

    //!p1 --> parameter of x EX: 3x --> 3 is parameter
    double p1_x1, p2_x1;
    //!pow --> power of x EX: x^2 --> 2 is power
    double pow1_x1, pow2_x1;

    double p1_x2, p2_x2;
    double pow1_x2, pow2_x2;

    //!num_f1 --> shift number for equation EX: x + 5 --> 5 is shift number
    double num_f1;
    double num_f2;

    cout << "Enter Equation 1" << endl;
    p1_x1=setData("x1 Parameter :");
    pow1_x1=setData("x1 power :");
    cout << endl;

    p1_x2=setData("x2 Parameter :");
    pow1_x2=setData("x2 power :");
    cout << endl;

    num_f1=setData("integer number :");
    cout << "\n____________________________________________________\n\n";

    cout << "Enter Equation 2" << endl;
    p2_x1=setData("x1 Parameter :");
    pow2_x1=setData("x1 power :");
    cout << endl;

    p2_x2=setData("x2 Parameter :");
    pow2_x2=setData("x2 power :");
    cout << endl;

    num_f2=setData("integer number :");
    cout << "\n____________________________________________________\n\n";

    cout << "Enter the initial point" << endl;
    x1=setData("X1 :");
    x2=setData("X2 :");

    //! iteration to find x1 , x2
    for (int i = 0; i < 2; i++)
    {
        double f1 = (p1_x1 * pow(x1, pow1_x1)) + (p1_x2 * pow(x2, pow1_x2)) + num_f1;
        double df1_x1 = p1_x1 * pow1_x1 * pow(x1, pow1_x1 - 1);
        double df1_x2 = p1_x2 * pow1_x2 * pow(x2, pow1_x2 - 1);

        double f2 = (p2_x1 * pow(x1, pow2_x1)) + (p2_x2 * pow(x2, pow2_x2)) + num_f2;
        double df2_x1 = p2_x1 * pow2_x1 * pow(x1, pow2_x1 - 1);
        double df2_x2 = p2_x2 * pow2_x2 * pow(x2, pow2_x2 - 1);

        double Invars_p = 1 / ((df1_x1 * df2_x2) - (df1_x2 * df2_x1));

        double Invars_df[2][2] =
            {
                {Invars_p * df2_x2, Invars_p * -df1_x2},
                {Invars_p * -df2_x1, Invars_p * df1_x1}};

        double matrix_x[2][1] =
            {
                {x1},
                {x2}};

        double matrix_f[2][1] =
            {
                {f1},
                {f2}};

        double multiply[2][1];

        for (int i = 0; i < 2; i++)
        {
            multiply[i][0] = 0;
            for (int j = 0; j < 2; j++)
            {
                multiply[i /*1*/][0] += Invars_df[i /*1*/][j /*0*/] * matrix_f[j /*0*/][0];
            }
        }
        double result[2][1];

        for (int i = 0; i < 2; i++)
        {
            result[i][0] = matrix_x[i][0] - multiply[i][0];
        }
        x1 = result[0][0];
        x2 = result[1][0];
    }

    cout << "\n___________________________________________________________\n\n";
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2;
}
