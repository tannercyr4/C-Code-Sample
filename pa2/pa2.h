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
#ifndef PA2_H
#define PA2_H

#include <stdio.h> /* Include the standard input/output library for functions
                      printf ( ) and scanf ( )*/
#include <math.h>  /* Included for sqrt ( ), sin ( ), and cos ( ) */

#define PI 3.141592 /* Define a constant macro to represent PI for the relevant equations */

double calculate_newtons_2nd_law (double mass, double acceleration);
double calculate_volume_cylinder (double radius, double height);
char perform_character_encoding (char plaintext_character, int shift);
double calculate_distance_between_2pts (double x1, double x2, double y1, double y2);
double calculate_tangent_theta (double theta);
double calculate_parallel_resistance (int r1, int r2, int r3);
double calculate_general_equation (int a, double x, double y, double z);

#endif