/**************************************************************************************************
 * Programmer: Tanner Cyr                                                                         *
 * Class: CptS 121, Fall 2013; Lab Section 0                                                      *
 * Programming Assignment: Solution to Programming Assignment #2 -                                *
 *                         A Modular Approach to Equation Evaluator                               *
 * Date: September 1, 2013                                                                        *
 *                                                                                                *
 * Description: This program evaluates seven different equations.                                 *
 *              The constants represent coefficients and                                          *
 *              coordinates that are used in the provided equations.                              *
 *              The user is prompted to enter the values, and the formulas                        *
 *              listed below are evaluated based on the user input.                               *
 *              The equations are displayed with the constants and results.                       *
 *                                                                                                *
 *              Inputs: acceleration, mass, radius, cylinder_height, plaintext_character, shift,  *
 *                      x1, x2, y1, y2, theta, R1, R2, R3, x, y, z, a                             *
 *              Constants: PI                                                                     *
 *              Computations: See relevant formulas                                               *
 *              Outputs: force, volume_cylinder, encoded_character,                               *
 *                       distance, tan_theta, parallel_resistance, y                              *
 *                                                                                                *
 *              This program does not provide error checking and only                             *
 *              uses sequential statements. This program defines only one                         *
 *              function, main ().                                                                *
 *                                                                                                *
 * Relevant Formulas (The equation numbers are referenced in the comments of                      *
 *                    the program):                                                               *                                                          
 *          (1)Newton's 2nd Law: force = mass * acceleration                                      *
 *          (2)Volume of a cylinder: volume_cylinder = PI * radius^2 * cylinder_height            *
 *          (3)Character encoding: encoded_character = (plaintext_character - 'A') + 'a' + shift  *
 *          (4)Distance between two points: distance = square root of ((x1 - x2)^2 + (y1 - y2)^2) *
 *          (5)Tangent: tan_theta = sin (theta) / cos (theta)                                     *
 *          (6)Equiv. parallel resistance: parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3)   *
 *          (7)General equation: y = (7 / 10) - y * z + x / (a % 2) + PI                          *
 *************************************************************************************************/

#include "pa2.h"

int main (void) /* The main ( ) function is the starting point of the program */
{
	int a = 0,		/* Stores the value for the user inputted a coefficient in equation (7) */
		shift = 0,	/* Stores the shift key inputted for the character encoding equation (3) */
	    resistance1 = 0,	/* Stores the first resistor value entered by the user for equaion (6) */
		resistance2 = 0,		/* Stores the second resistor value entered by the user for equaion (6) */
		resistance3 = 0;	/* Stores the third resistor value entered by the user for equaion (6) */

	char plaintext_character = '\0', /* Stores the character inputted by the user for use in equation (3) */
		 encoded_character = '\0';   /* Stores the result of the encoding from equation (3) */

	double mass = 0.0,                  /* Stores the mass in grams of the value inputted by the user for equation (1) */
		   acceleration = 0.0,          /* Stores the acceleration in m/s^2 of the value inputted by the user for equation (1) */
		   force = 0.0,                 /* Stores the result of equation (1) */
		   radius = 0.0,                /* Stores the radius of the cylinder inputted by the user for equation (2) */
		   cylinder_height = 0.0,       /* Stores the height of the cylinder inputted by the user for equation (2) */
		   volume_cylinder = 0.0,       /* Stores the result of equation (2) */
		   x1 = 0.0,					/* Stores the x1 value inputted by the user for equation (4) */
		   x2 = 0.0,					/* Stores the x2 value inputted by the user for equation (4) */
		   y1 = 0.0,					/* Stores the y1 value inputted by the user for equation (4) */
		   y2 = 0.0,					/* Stores the y2 value inputted by the user for equation (4) */
		   distance = 0.0,				/* Stores the distance between two points computed from equation (4) */
		   theta = 0.0,                 /* Stores the theta angle inputted by the user for equation (5) */
		   tan_theta = 0.0,			    /* Stores the result of equation (5) */
		   parallel_resistance = 0.0,	/* Stores the equivalent resistance based on three resistors connected in parallel for equation (6) */
		   x = 0.0,                     /* Stores x value inputted by user for equation (7) */
		   z = 0.0,                     /* Stores z value inputted by user for equation (7) */
		   y = 0.0;                     /* Stores the value inputted by the user and also the result of the general equation (7) */

	printf ("*************** WELCOME TO THE EQUATION EVALUATOR **************\n\n");

	/* Prompt the user for 2 floating-point values that are used in Netwon's 2nd Law of Motion
	   equation (1) */
	printf ("Please enter the mass and acceleration (both floating-point values) for use in Newton's Second Law: ");
	
	/* Read the floating-point values into the proper variables: do not forget the
	   "address of" operator (&) before each variable */
	scanf ("%lf%lf", &mass, &acceleration);

	/* Calculate the result of equation (1), which is force on an object
	   provided its mass and acceleration */
	force = calculate_newtons_2nd_law (mass, acceleration);

	/* Print out the result of equation (1) */
	printf ("Newton's Second Law: force = mass * acceleration = %lf * %lf = %.2lf\n", 
		     mass, acceleration, force);



	/* Prompt the user for 2 floating-point values that are used in volume of a cylinder
	   equation (2) */
	printf ("\nPlease enter the radius and height (both floating-point values) for use in a volume of cylinder equation: ");
	
	/* Read the floating-point values into the proper variables that are used in equation (2) */
	scanf ("%lf%lf", &radius, &cylinder_height);

	/* Calculate the result of equation (2), which is the volume of the cylinder
	   derived from radius and height of it */
	volume_cylinder = calculate_volume_cylinder (radius, cylinder_height);

	/* Print out the result of equation (2) */
	printf ("Volume of a cylinder: volume_cylinder = PI * radius^2 * height = %lf * %lf^2 * %lf = %.2lf\n", 
		     PI, radius, cylinder_height, volume_cylinder);

	

	/* Prompt the user for 1 character value for use in equation (3) */
	printf ("\nPlease enter the plaintext character and integer shift key for use in a character encoding equation: ");
	
	/* Read the character into the proper variable that is used in equation (3) */
	/* Recall a space between the " and %c ignores all white space characters */
	scanf (" %c%d", &plaintext_character, &shift);

	/* Calculate the result of equation (3), which is the encoded character */
	encoded_character = perform_character_encoding (plaintext_character, shift);

	/* Print out the result of equation (3) */
	printf ("Character encoding: encoded_character = (plaintext_character - 'A') + 'a' + shift = %c - %c + %c + %d = %c\n", 
		     plaintext_character, 'A', 'a', shift, encoded_character);


	
	/* Prompt the user for the coordinates of two points for use in equation (4) */
	printf ("\nPlease enter the x1, y1, x2, and y2 (all floating point values) for use in a distance between points equation: ");
	
	/* Read in the floating-point values in the correct order for equation (4) */
	scanf ("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	
	/* Calculate the distance between points for equation (4) */
	distance = calculate_distance_between_2pts (x1, x2, y1, y2);

	/* Print out the distance between two points derived from equation (4) */
	printf ("\nDistance between 2 pts: distance = sqrt ((x1 - x2)^2 + (y1 - y2)^2)\n");
	printf (" = sqrt ((%lf - %lf)^2 + (%lf - %lf)^2) = %.2lf\n", x1, x2, y1, y2, distance);



	/* Prompt the user for 1 floating-point value that for use in equation (5) */
	printf ("\nPlease enter the angle (a floating-point value) for use in determining the tangent of an angle: ");
	
	/* Read the floating-point value into the proper variables for equation (5) */
	scanf ("%lf", &theta);

	/* Calculate the result of equation (5), which is the tangent of an angle */
	tan_theta = calculate_tangent_theta (theta);

	/* Print out the result of equation (5) */
	printf ("Tangent: tan_theta = sin (theta) / cos (theta)\n");
	printf (" = sin(%lf) / cos(%lf) = %.2lf\n", theta, theta, tan_theta);
		     


	/* Prompt the user for 3 integers that are used in the equivalent parallel resistance
	   equation (6) */
	printf ("\nPlease enter three resistance values (all integers) for use in\n");
	printf (" parallel resistance equation: ");
	
	/* Read the integer values into the proper variables for equation (6) */
	scanf ("%d%d%d", &resistance1, &resistance2, &resistance3);

	/* Calculate the parallel resistance for equation (6) */
	parallel_resistance = calculate_parallel_resistance (resistance1, resistance2, resistance3);

	/* Print out the result of equation (6) */
	printf ("Equivalent parallel resistance: parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3) = 1 / (1 / %d + 1 / %d + 1 / %d) = %.2lf\n", 
		     resistance1, resistance2, resistance3, parallel_resistance);


	/* Prompt the user for 2 floating-point and 1 integer values to be used
	   in the general equation calculation (7) */
	printf ("\nPlease enter x, y, and z (all floating_point values) and a (an integer value)\n");
	printf (" for use in a general equation: ");

	/* Get the values needed for equation (7) */
	scanf ("%lf%lf%lf%d", &x, &y, &z, &a);
	printf ("general equation: y = 7/10 - y * z + x / (a %% 2) + PI\n = %lf - %lf * %lf + %lf * / (%d %% 2) + %lf = ", ((double) 7 / 10), y, z, x, a, PI);

	/* Calculate the result of equation (7), the result is a y-coordinate */
	y = calculate_general_equation (a, x, y, z);

	/* Print the result of the general equation (7) */
	printf ("%.2lf\n\n", y);

	return 0;
} /* End of program */