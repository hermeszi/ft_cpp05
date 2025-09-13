/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/09/13 18:31:22 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

using std::cout;
using std::endl;

static void line(const std::string& title = "")
{
    size_t n = title.size();
    if (n > 40)
        n = 40;
    
    cout << "\n==== " 
         << title 
         << " " 
         << std::string(40 - n, '=')
         << endl;
}

int main() {
// ---------------- ex00: Bureaucrat basic construction & streaming ----------------
    line("ex00: construct & print");
    try
    {
        Bureaucrat a("Alice", 1);
        Bureaucrat b("Bob", 150);
        cout << a << "\n";
        cout << b << "\n";
    } 
    catch (const std::exception& e)
    {
        cout << "Unexpected exception: " << e.what() << endl;
    }

// ---------------- ex00: invalid construction ----------------
    line("ex00: invalid construction");
    try
    {
        Bureaucrat badHigh("TooHigh", 0); // should throw GradeTooHigh
        (void)badHigh;
    }
    catch (const std::exception& e) 
    {
        cout << "Caught (0): " << e.what() << endl;
    }
    try
    {
        Bureaucrat badLow("TooLow", 151); // should throw GradeTooLow
        (void)badLow;
    }
    catch (const std::exception& e) 
    {
        cout << "Caught (151): " << e.what() << endl;
    }

    // ---------------- ex00: increment/decrement boundaries ----------------
    line("ex00: increment/decrement");
    try 
    {
        Bureaucrat c("Carol", 2);
        cout << c << "\n";
        c.incrementGrade(); // goes to 1
        cout << c << "\n";
        try
        {
            c.incrementGrade(); // should throw (would go above 1)
        }
        catch (const std::exception& e)
        {
            cout << "increment at 1 -> exception: " << e.what() << endl;
        }
    } 
    catch (const std::exception& e) 
    {
        cout << "Unexpected: " << e.what() << endl;
    }

    try
    {
        Bureaucrat d("Dave", 149);
        cout << d << "\n";
        d.decrementGrade(); // goes to 150
        cout << d << "\n";
        try
        {
            d.decrementGrade(); // should throw (would go below 150)
        } 
        catch (const std::exception& e)
        {
            cout << "decrement at 150 -> exception: " << e.what() << endl;
        }
    } 
    catch (const std::exception& e) 
    {
        cout << "Unexpected: " << e.what() << endl;
    }

// // ---------------- ex01: AForm basics ----------------
//     line("ex01: AForm construct & print");
//     try
//     {
//         AForm f1("TopSecret", 10, 5);
//         AForm f2("Trivial", 150, 150);
//         cout << f1 << "\n";
//         cout << f2 << "\n";
//     } 
//     catch (const std::exception& e)
//     {
//         cout << "AForm construction exception: " << e.what() << endl;
//     }

// // ---------------- ex01: AForm invalid construction ----------------
//     line("ex01: AForm invalid construction");
//     try { AForm bad1("BadSignHigh", 0, 50); }
//     catch (const std::exception& e) { cout << "Caught bad1: " << e.what() << endl; }
//     try { AForm bad2("BadSignLow", 151, 50); }
//     catch (const std::exception& e) { cout << "Caught bad2: " << e.what() << endl; }
//     try { AForm bad3("BadExecHigh", 50, 0); }
//     catch (const std::exception& e) { cout << "Caught bad3: " << e.what() << endl; }
//     try { AForm bad4("BadExecLow", 50, 151); }
//     catch (const std::exception& e) { cout << "Caught bad4: " << e.what() << endl; }

// // ---------------- ex01: beSigned directly ----------------
//     line("ex01: beSigned");
//     try
//     {
//         Bureaucrat chief("Chief", 5);
//         Bureaucrat peon("Peon", 140);
//         AForm tough("ToughForm", 10, 10);
//         AForm easy("EasyForm", 140, 140);

//         cout << tough << "\n" << easy << "\n";

//         // peon fails on tough (needs 10)
//         try
//         {
//             tough.beSigned(peon);
//             cout << "Unexpected: peon signed tough\n";
//         } 
//         catch (const std::exception& e) 
//         {
//             cout << "peon failed to sign tough: " << e.what() << endl;
//         }

//         // chief signs tough
//         try
//         {
//             tough.beSigned(chief);
//             cout << "chief signed tough\n";
//         }
//         catch (const std::exception& e)
//         {
//             cout << "Unexpected: chief failed: " << e.what() << endl;
//         }

//         // peon signs easy (140 required)
//         try
//         {
//             easy.beSigned(peon);
//             cout << "peon signed easy\n";
//         } catch (const std::exception& e)
//         {
//             cout << "Unexpected: peon failed: " << e.what() << endl;
//         }

//         cout << tough << "\n" << easy << "\n";
//     } 
//     catch (const std::exception& e)
//     {
//         cout << "Unexpected: " << e.what() << endl;
//     }

// // ---------------- ex01: Bureaucrat::signForm wrapper ----------------
//     line("ex01: Bureaucrat::signForm");
//     try
//     {
//         Bureaucrat exec("Exec", 50);
//         Bureaucrat junior("Junior", 120);
//         AForm mid("MidForm", 75, 75);
//         AForm hard("HardForm", 25, 25);

//         exec.signForm(mid);   // should succeed (50 <= 75)
//         junior.signForm(mid); // already signed; your beSigned may ignore or keep signed
//         junior.signForm(hard); // should fail (120 > 25)
//     }
//     catch (const std::exception& e)
//     {
//         cout << "Unexpected: " << e.what() << endl;
//     }

//     line("done");
//     return 0;
}
