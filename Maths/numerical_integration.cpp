#include <iostream>
#include <math.h>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#define PI 3.14159265359
using namespace std;
typedef double dd;

// global array to store coefficient and power of polynomial

dd coeff[1000], power[1000][10];

// 2d array for eqations like xsin^4xcos^5x 

char equation[1000][10];

int size;

// If the function cannot be given as input then hardcode the function

/*
 dd EQUATION(dd x) {
     dd value = 0;
     value = pow(2.71828, -(x*x)/2) / sqrt(2*PI);
     return value;
 }
*/

// This is how the function looks like

void visualise() {
    cout << "F(x) = ";

    for (int i = 0; i < size; ++i) {
    	
    	if (coeff[i] > 0)
	        cout << "+";
	    cout << coeff[i];
    	for (int j = 0; j < 10; ++j) {
    		
	        if (equation[i][j] == 'x')
	            cout << "x^"<< power[i][j];
	    
	        if (equation[i][j] == 's')
	            cout << "sin^" <<power[i][j]<<"(x)";
	    
	        if (equation[i][j] == 'c')
	            cout << "cos^" << power[i][j] << "(x)";
	    
	        if (equation[i][j] == 't')
	            cout << "tan^" << power[i][j] << "(x)";
	    
	        if (equation[i][j] == 'l')
	            cout << "log^" << power[i][j] << "(x)";
	    
	        if (equation[i][j] == 'e')
	            cout << "e^" << power[i][j] << "x";
	        
	        if (equation[i][j] == '1')
	            cout <<"";

	    }
	}
}

//evaluate the value of function
dd EQUATION(dd x) {
    dd value = 0;
    dd factor;

    for (int i = 0; i < size; ++i) {
        factor = coeff[i];
        for (int j = 0; j < 10; j++) {

            if (equation[i][j] == 'x')
                factor = factor*pow(x, power[i][j]);

            if(equation[i][j] == 's')
                factor = factor*pow(sin(x), power[i][j]);

            if(equation[i][j] == 'c')
                factor = factor*pow(cos(x), power[i][j]);

            if(equation[i][j] == 't') {

                factor = factor*pow(tan(x), power[i][j]);
            }

            if(equation[i][j] == 'e')
                factor = factor*pow(exp(x), power[i][j]);

            if(equation[i][j] == 'l') {
                factor = factor*pow(log(x), power[i][j]);
            }

            if(equation[i][j] == '1')
                factor = factor * 1;
        }
        value = value + factor;
    }
    return value;
}
//===============================================================================================================//

// composite midpoint theorem implementation
dd MIDPOINT_EQUATION(dd a, dd b, dd n) {
    dd area = 0;
    dd h = (b-a)/n;

    for (dd i = 1; i <= n; i++) {
        area = area + h*EQUATION(a+(i-0.5)*h);
    }
    return area ;
}

// composite rectangle method
dd RECTANGULAR_EQUATION(dd a, dd b, dd n) {
    dd area = 0;
    dd h = (b-a) / n;
    for (int i = 0; i < n; ++i) {
        area = area + h*EQUATION(a+i*h);
    }
    return area;
}

// composite trapezoidal theorem implementation
dd TRAPEZOIDAL_EQUATION(dd a, dd b, dd n) {
    dd temp = 0, area = 0;
    dd h = (b-a)/n;
    temp = temp + EQUATION(a) + EQUATION(b);
        for (dd i = 1; i < n; i++)
    temp = temp + 2 * EQUATION(a + i*h);
    area = temp * (b-a)/(2*n);
    return area;
}

// composite simpson's theorem implementation
dd SIMPSON_EQUATION(dd a, dd b, dd n) {
    dd area;
    dd temp;
    dd h = (b-a)/n;
    temp = EQUATION(a) + EQUATION(b);
    dd odd_sum = 0, even_sum = 0;
    for (int i = 1; i < n; ++i) {
        if (i%2)
            odd_sum += EQUATION(a + i*h);
        else
            even_sum += EQUATION(a + i*h);
    }
    odd_sum = 4 * odd_sum;
    even_sum = 2 * even_sum;
    area = h/3*(temp + odd_sum + even_sum);
    return area;
}

// romberg theorem implementation
dd ROMBERG_EQUATION(dd a, dd b) {
    dd r[10][10]; // note here n is fixed to 10 for computation purpose you can change the size of the array r size
    r[1][1] = 0.5 * (b-a) * (EQUATION(a) + EQUATION(b));
    for (int i = 2; i < 10; ++i) {
    dd area = 0;
    for (int k = 1; k <= pow(2, i-2); ++k)
       area = area + EQUATION(a + (2*k-1)*(b-a)/pow(2, i-1));
        r[i][1] = 0.5 * r[i-1][1] + (b-a)/pow(2, i-1) * area;
    }


    for (int i = 2; i < 10; ++i)
        for (int j = 2; j <= i; ++j)
            r[i][j] = r[i][j - 1] + (r[i][j - 1] - r[i - 1][j - 1]) / (pow(4, j - 1) - 1);
    return r[9][9];
}

int main() {

    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 10; j++)
            equation[i][j] = '1';
    
    char ch, flush;
    
    cout << endl;
    cout << "Program supports Integration of two terms" << endl;
    cout << "Usage:" << endl;
    cout << "To enter F(x) = 3sin^5(x)cos^7(x) give input 3 s 5 c 7" << endl;
    cout << endl;

    dd a, b; //enter lower and upper bound
    int n, opt; // number of iterations
    clock_t t; // computational time
    dd time_taken;
    int tan_flag;
    while (1) {
    	tan_flag = 0;
        /* polynomial input*/
        
        cout << endl;
        cout << "Enter the number of terms in the polynomial" << endl;
        cin >> size;
        cout << "Enter the coefficient, function and power of the equation" << endl;

        /*
        if the polynomial is ax^2 + b^x + c;
        enter in the format a 2 b 1 c 0;
        */
        
        for (int i = 0; i < size; ++i) {
            cin >> coeff[i];
            for (int j = 0; j < 10; ++j) {
                flush = getchar();
                if (flush == '\n')
                    break;
                cin >> equation[i][j];
                if (equation[i][j] == 't')
                	tan_flag = 1;
                cin >> power[i][j];
                // cout << equation[i][j] << endl;
                // if (equation[i][j] == '\n')
                    // break;
            }
        }
        // Calling function to see how the function actually looks like
        visualise();
        
        LOOP:
            cout << endl ;
            cout << "Enter lower bound: \n";
            cin >> a;
            cout << "Enter upper bound: \n";
            cin >> b;
            cout << "Enter number of iterations: \n";
            cin >> n;


            if ((int(floor((b*2)/PI) - floor((a*2)/PI)) % 2) && tan_flag == 1) {
                cout << "Divergent";
                goto LOOP;
            }
            dd h = (b-a)/n;

            cout << endl;
            cout << "Numerical Methods of Integration: " << endl;

            cout << "1. Midpoint Rule: ";
            t = clock();
            cout << MIDPOINT_EQUATION(a, b, n) << endl;
            t = clock() - t;
            time_taken = ((double)t)/CLOCKS_PER_SEC;
            cout << "   Computation Time: " << time_taken << endl << endl;

            cout << "2. Rectangle Rule: ";
            t = clock();
            cout << RECTANGULAR_EQUATION(a, b, n) << endl;
            t = clock() - t;
            time_taken = ((double)t)/CLOCKS_PER_SEC;
            cout << "   Computation Time: " << time_taken << endl << endl;

            cout << "3. Trapezoidal Rule: ";
            t = clock();
            cout << TRAPEZOIDAL_EQUATION(a, b, n) << endl << endl;
            t = clock() - t;
            time_taken = ((double)t)/CLOCKS_PER_SEC;
            cout << "   Computation Time: " << time_taken << endl << endl;

            cout << "4. Simpsons Rule: ";
            t = clock();
            cout << SIMPSON_EQUATION(a, b, n) << endl;
            t = clock() - t;
            time_taken = ((double)t)/CLOCKS_PER_SEC;
            cout << "   Computation Time: " << time_taken << endl << endl;

            cout << "5. Romberg Rule: ";
            t = clock();
            cout << ROMBERG_EQUATION(a, b) << endl;
            t = clock() - t;
            time_taken = ((double)t)/CLOCKS_PER_SEC;
            cout << "   Computation Time: " << time_taken << endl << endl;

        cout << endl;
        cout << "Press 0 to exit" << endl;
        cout << "Press 1 to change integral bounds" << endl;
        cout << "Press 2 to change the function"<< endl;

        cin >> opt;
        if(opt == 1)
            goto LOOP;
        if(opt == 2)
            continue;
        else
            exit(0);
        }

    return 0;	
}
