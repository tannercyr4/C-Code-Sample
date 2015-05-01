/**************************************************************************************************
 * Programmer: Andrew S. O'Fallon                                                                 *
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

/*************************************************************
 * Function: calculate_newtons_2nd_law ()                    *
 * Date Created: September 3,2013                            *
 * Date Last Modified: September 3,2013                      *
 * Description: This function calculates the force on an     *
 *              object based on its mass and acceleration.   *
 * Input parameters: Mass and acceleration of an object      *
 * Returns: The force applied to the object.                 *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

double calculate_newtons_2nd_law (double mass, double acceleration)
{
	double force = 0.0;

	force = mass * acceleration;

	return force;
}

/*************************************************************
 * Function: calculate_volume_cylinder ()                    *
 * Date Created: September 3,2013                            *
 * Date Last Modified: September 3,2013                      *
 * Description: This function calculates volume of a cylinder*
 *              provided the radius of the base circle and   *
 (              its height.                                  *
 * Input parameters: The radius and height of a cylinder.    *
 * Returns: The volume of a cylinder.                        *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

double calculate_volume_cylinder (double radius, double height)
{
	double volume = 0.0;

	volume = PI * radius * radius * height;

	return volume;
}

/*************************************************************
 * Function: character_encoding ()                           *
 * Date Created: September 3,2013                            *
 * Date Last Modified: September 3,2013                      *
 * Description: This function applies a constant shift key   *
 *              to a character to encode it.                 *
 * Input parameters: The plaintext character to encode.      *
 * Returns: An encoded character.                            *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

char perform_character_encoding (char plaintext_character, int shift)
{
	char encoded_character = '\0';

	encoded_character = (plaintext_character - 'A') + 'a' + shift;

	return encoded_character;
}

/*************************************************************
 * Function: calculate_distance_between_2pts                 *
 * Date Created: September 3,2013                            *
 * Date Last Modified: September 3,2013                      *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

double calculate_distance_between_2pts (double x1, double x2, double y1, double y2)
{
	double distance = 0.0;

	distance = sqrt (((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

	return distance;
}

/*************************************************************
 * Function: calculate_tangent_theta ()                      *
 * Date Created: September 3,2013                            *
 * Date Last Modified: September 3,2013                      *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

double calculate_tangent_theta (double theta)
{
	double tan_theta = 0.0;

	tan_theta = sin (theta) / cos (theta);

	return tan_theta;
}

/*************************************************************
 * Function: calculate_parallel_resistance ()                *
 * Date Created: September 3,2013                            *
 * Date Last Modified: September 3,2013                      *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

double calculate_parallel_resistance (int r1, int r2, int r3)
{
	double parallel_resistance = 0.0;

	/* Calculate the parallel resistance for equation (6) */
	parallel_resistance = 1 / (1 / (double) r1 + 1 / (double) r2 + 1 / (double) r3); // Cast the integer resistances to obtain more precision in evaluation

	return parallel_resistance;
}

/*************************************************************
 * Function: calculate_general_equation ()                   *
 * Date Created: September 3,2013                            *
 * Date Last Modified: September 3,2013                      *
 * Description: This function calculates the y value for     *
 *              an equation that applies 5 different         *
 *              mathematical operators.                      *
 * Input parameters: Integer a, doubles x, y, and z          *
 * Returns: The y value.                                     *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

double calculate_general_equation (int a, double x, double y, double z)
{
	/* Calculate the result of equation (7), the result is a y-coordinate */
	y = ((double) 7 / 10) - y * z + x / (a % 2) + PI;

	return y;
}