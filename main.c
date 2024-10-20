#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculate_function(float arg_val);
float start_val_input(void);
int end_val_input(float starting_value);
float coefficient_val_input(void);
float step_val_input(void);



int main(void) {
	// Get input 
	printf("This program calculates the values for the function f(x)=2-sqrt(1+sqrt(4-x^2)/1+5x) in up to 20 different points.\n\n");
	const int max_calc_points = 20;
	double argument_values[max_calc_points];
	long double calculated_values[max_calc_points]; 
	double starting_val, end_val, step_val, coefficient_val, func_formula_val, power_factor; 
	double x_arg_val; 
	end_val = end_val_input(starting_val = start_val_input());
	step_val = step_val_input();
	coefficient_val = coefficient_val_input();


	x_arg_val = starting_val; 
	power_factor = 0.00; 
	for(int i = 0; i < max_calc_points && x_arg_val < end_val; ++i) {
		if(i == 0) {
			argument_values[i] = starting_val;
			printf("%lf\n", argument_values[i]);
			++i; 
		}
		x_arg_val += step_val*pow(coefficient_val, power_factor);
		argument_values[i] = x_arg_val; // argument_values[1] = A+H
		if(i >= 1) {
			++power_factor;
		}
		
		
	}

	for(int j = 0; j < power_factor; ++j) {
		calculated_values[j] = calculate_function(argument_values[j]);
		printf("%lf\n", calculated_values[j]);
	}


	return 0;
}

float calculate_function(float argument_value) {
	long double f_formula = 2.00 - sqrt(1.00+(sqrt(4.00-pow(argument_value, 2.00))/(1.00+5.00*argument_value)));
	return f_formula;
}

float start_val_input(void) {
	float start_val;
	printf("Enter the starting value for the function: ");
	scanf("%f", &start_val);
	return start_val; 
}

int end_val_input(float starting_value) {
	double end_val = 0;
	while(!end_val || end_val <= starting_value) {
		printf("Enter the ending value for which you want to calculate: ");
		scanf("%lf", &end_val);
		if(end_val <= starting_value) {
			printf("[-] Ending value cannot be smaller than the starting value of the function.\n");
			printf("[*] Enter a valid ending value.\n");
		}
	}
	
	return end_val; 
}

float step_val_input(void) {
	double step_val = 0; 
	while(!step_val || step_val < 0) {
		printf("Enter stepping value for the function calculations: ");
		scanf("%lf", &step_val);
		if(step_val < 0) {
			printf("[-] Stepping value must be bigger than 0.\n");
		}
	} 
	
	return step_val; 
}

float coefficient_val_input(void) {
	double coefficient_val = 0; 
	while(!coefficient_val || coefficient_val < 1) {
		printf("Enter the coefficient value for the function: ");
		scanf("%lf", &coefficient_val);
		if(coefficient_val < 1) {
			printf("[-] Coefficient value must be bigger than or equal to 1.\n");
		}
	} 
	
	return coefficient_val;
}
