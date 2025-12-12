/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12                                    #+#    #+#       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

static void header(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

static void showFile(const std::string& path)
{
    std::ifstream in(path.c_str());
    if (!in.is_open())
    {
        std::cout << "File check: cannot open '" << path << "' (not created?)\n";
        return;
    }

    std::cout << "File check: '" << path << "' contents:\n";
    std::string line;
    while (std::getline(in, line))
        std::cout << line << "\n";
}

int main()
{
    header("Create form + try execute BEFORE signing (should fail / print 'Form not signed!')");
    try
    {
        ShrubberyCreationForm f("home");
        Bureaucrat exec("ExecGuy", 1);

        std::cout << f << std::endl;

        // should fail because not signed yet
        try { f.execute(exec); }
        catch (const AForm::FormNotSignedException& e) { std::cout << "Caught execute exception: " << e.what() << "\n"; }
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << "\n";
    }

    header("Try sign with LOW grade (should fail)");
    try
    {
        ShrubberyCreationForm f("garden");
        Bureaucrat low("LowGuy", 150);

        low.signForm(f); // should print couldn't sign ... Grade too LOW
        std::cout << f << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << "\n";
    }

    header("Sign OK, then execute with LOW executor grade (should throw GradeTooLowException)");
    try
    {
        ShrubberyCreationForm f("park");
        Bureaucrat signer("Signer", 1);     // strong enough to sign
        Bureaucrat lowExec("LowExec", 150); // too weak to execute

        signer.signForm(f);
        std::cout << f << std::endl;

        try { f.execute(lowExec); }
        catch (const std::exception& e) { std::cout << "Caught execute exception: " << e.what() << "\n"; }

        // file should NOT be created on failure
        showFile("park_shrubbery");
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << "\n";
    }

    header("Sign OK, execute OK (should create <target>_shrubbery)");
    try
    {
        ShrubberyCreationForm f("office");
        Bureaucrat signer("Signer", 1);
        Bureaucrat exec("Exec", 1);

        signer.signForm(f);

        try { f.execute(exec); }
        catch (const std::exception& e) { std::cout << "Execute exception: " << e.what() << "\n"; }

        showFile("office_shrubbery");
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << "\n";
    }

    return 0;
}
